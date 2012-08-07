#ifndef _Session_H
#define _Session_H

// Session

// Session stores/maintains information about an authenticated logical connection
// between servers/clients.  Sessions are only apply to authenticated connections;
// do not create sessions for unauthenticated connections within a client/server.

// There are two types of sessions: non-remote and remote.  Non-remote sessions are
// generated by the server and are unique within the server.  Remote sessions are
// generated by a remote source and may or may not be unique within the server.  Note
// that the uniqueness of a Session is determined only by its id.

// Sessions contain a unique id (ushort), encryption attributes, a time stamp for
// the last use of the session, symmetric key for encryption/decryption (optional),
// AuthCertificate used to created the session (optional), and sequence numbers for
// encryption/decryption (optional).

// Session instances are created by authentication protocols, maintained by the
// SessionMgr, and used by encryption protocols.

// NOTE: Only the Id, isRemote, EncryptAttributes, SymmetricKey, and AuthCertificate 
// are not mutable within a Session.  Is expected and desired that other members be
// updated on const instances.


#include <time.h>
#include "common/won.h"
#include "common/CriticalSection.h"
#include "AuthCertificateBase.h"
#include "Auth1Certificate.h"
#include "CryptFlags.h"

// Forwards
namespace WONCrypt {
	class SymmetricKey;
};

namespace WONFramework {
	class SessionMgr;
};


// In the WONAuth namespace
namespace WONAuth {

// Forwards
struct SessionData;  // Real session object (sessions are ref counted)

// EncryptInfo
// Defines attributes of encryption on a session
struct EncryptAttributes
{
	// Note: EncryptMode == NONE implies all other attribute values are N/A.
	EncryptionMode mEncryptMode;  // Encryption type
	bool           mIsSequenced;  // Uses sequence numbers?
	bool           mIsSession;    // Uses session Ids?
	bool           mEncryptAll;   // All messages must be encrypted?

	explicit EncryptAttributes(EncryptionMode theMode=ENCRYPT_NONE, bool isSession=false) :
		mEncryptMode(theMode), mIsSequenced(true), mIsSession(isSession),
		mEncryptAll(true)
	{}
};


class Session
{
public:
	// Default Constructor - NOT RECOMMENDED FOR USE.
	// Exists to support STL containers which require a default ctor.  Instance
	// generated will be invalid until assigned to or Init() is called.
	Session();

	// Construct and init session.  Calls Init(); see comments on Init() for details
	// and restrictions.
	Session(const EncryptAttributes& theAttr, WONCrypt::SymmetricKey* theKeyP,
	        WONAuth::AuthCertificateBase* theCertP, unsigned short theId=0);

	// Copy Constructor
	Session(const Session& theSessR);

	// Destructor
	~Session();

	// Assignment operator
	Session& operator=(const Session& theSessR);

	// Logical operators
	bool operator==(const Session& theSessR) const;
	bool operator!=(const Session& theSessR) const;
	bool operator< (const Session& theSessR) const;
	bool operator<=(const Session& theSessR) const;
	bool operator> (const Session& theSessR) const;
	bool operator>=(const Session& theSessR) const;

	// Check validity.  (Key and cert must be set if EncryptMode is not NONE).
	bool IsValid() const;

	// Compare two sesions (simply compares the ids only)
	int Compare(const Session& theSessR) const;

	// Initialize a session
	// Initializes a new session with specified attributes.  If theId is 0, a new
	// session id is generated and session is non-remote.  If theId is non-zero,
	// a remote session is generated with the specified id.
	// *NOTE* The key and cert MUST BE dynamically allocated.  Session will take
	// ownership of them and delete then when destructed.
	// *NOTE* Calling init breaks ref link with any other instances sharing the
	// current session.  Current session is overwritten.
	void Init(const EncryptAttributes& theAttr, WONCrypt::SymmetricKey* theKeyP,
	          WONAuth::AuthCertificateBase* theCertP, unsigned short theId=0);

	// Session Id access
	unsigned short GetId() const;

	// Is this a remote session (generated with a specified session id)
	bool IsRemote() const;

	// Is session authenticated?  (non-null certificate)
	bool IsAuthenticated() const;

	// Shortcuts to user auth info from certificate
	// Returns 0 if cert is NULL
	unsigned long  GetUserId() const;
//	unsigned long  GetCommunityId() const;
//	unsigned short GetTrustLevel() const;

	// Encryption Attributes
	const EncryptAttributes& GetEncryptAttr() const;
	EncryptionMode GetEncryptMode() const;
	bool IsSequenced() const;
	bool IsPersistent() const;
	bool IsAlwaysEncrypted() const;

	// Key and Certificate access - may be NULL.  NULL cert implies an
	// unauthenticated session.
	const WONCrypt::SymmetricKey* GetKey() const;
	const WONAuth::AuthCertificateBase* GetCert() const;
	const WONAuth::Auth1Certificate* GetAuth1Cert() const;

	// LastAction access
	time_t GetLastAction() const;
	void Touch() const;  // Set last action to current time

	// Sequencing - Get current sequence nums
	unsigned short GetLastRecvSeq() const;
	unsigned short GetLastSendSeq() const;

	// Sequencing - Get next sequence nums (returns ++seq)
	unsigned short GetNextRecvSeq() const;
	unsigned short GetNextSendSeq() const;

	// Test/Set sequence nums.  Verifies theSeq is expected value.  This implies
	// theSeq == (currSeq+1) is isReliable is true, or currSeq < theSeq if isReliable
	// is false.  If verify is true, currSeq is updated to theSeq.  Result of the
	// verify is returned
	bool TestSetRecvSeq(unsigned short theSeq, bool isReliable=true) const;
	bool TestSetSendSeq(unsigned short theSeq, bool isReliable=true) const;

	// Message counts
	unsigned short GetMsgsRecv() const;
	unsigned short GetMsgsSent() const;
	unsigned short GetMsgsProc() const;

	// Increment message count
	void IncMsgsRecv() const;
	void IncMsgsSent() const;
	void IncMsgsProc() const;

	// Dump to stream
	void Dump(std::ostream& os, bool verbose=false) const;

	// constant Invalid Session instance
	static const Session gInvalidSession;

private:
	SessionData* mRefP;  // reference counted object

	// Class Memeber for generating session Ids
	static unsigned short gNextSessionId;

	// Class method to fetch next session id
	static unsigned short GetNextSessionId();

	// Private constructor used by SessionMgr for searching
	friend class WONFramework::SessionMgr;
	explicit Session(unsigned short theId);

};


struct SessionData
{
	long                       mRefCt;        // Reference count
	unsigned short             mId;           // Session Id
	bool                       mIsRemote;     // Is this a remote session?
	EncryptAttributes          mEncryptAttr;  // Encryption attributes
	WONCrypt::SymmetricKey*    mKeyP;         // Key for encrypt/decrypt (optional)
	WONAuth::AuthCertificateBase* mCertP;        // Auth certificate (optional)
	mutable time_t             mLastAction;   // Last time session was used
	mutable unsigned short     mRecvSeq;      // Sequence number for receives
	mutable unsigned short     mSendSeq;      // Sequence number for sends
	mutable unsigned short     mRecvCt;       // Number of messages received
	mutable unsigned short     mSendCt;       // Number of messages sent
	mutable unsigned short     mProcCt;       // Number of messages processed

	// Critical section for thread safety.
	mutable WONCommon::CriticalSection mCrit;

	// Constructor/Destructor
	SessionData();
	~SessionData();

private:
	// Disable copy and assignment
	SessionData(const SessionData& theSessR);
	SessionData& operator=(const SessionData& theSessR);
};


// Inlines
inline bool
Session::operator==(const Session& theSessR) const
{ return (Compare(theSessR) == 0); }

inline bool
Session::operator!=(const Session& theSessR) const
{ return (Compare(theSessR) != 0); }

inline bool
Session::operator<(const Session& theSessR) const
{ return (Compare(theSessR) < 0); }

inline bool
Session::operator<=(const Session& theSessR) const
{ return (Compare(theSessR) <= 0); }

inline bool
Session::operator>(const Session& theSessR) const
{ return (Compare(theSessR) > 0); }

inline bool
Session::operator>=(const Session& theSessR) const
{ return (Compare(theSessR) >= 0); }

inline int
Session::Compare(const Session& theSessR) const
{ return (static_cast<int>(mRefP->mId) - static_cast<int>(theSessR.mRefP->mId)); }

inline unsigned short
Session::GetId() const
{ return mRefP->mId; }

inline const EncryptAttributes&
Session::GetEncryptAttr() const
{ return mRefP->mEncryptAttr; }

inline EncryptionMode
Session::GetEncryptMode() const
{ return mRefP->mEncryptAttr.mEncryptMode; }

inline bool
Session::IsSequenced() const
{ return mRefP->mEncryptAttr.mIsSequenced; }

inline bool
Session::IsPersistent() const
{ return mRefP->mEncryptAttr.mIsSession; }

inline bool
Session::IsAlwaysEncrypted() const
{ return mRefP->mEncryptAttr.mEncryptAll; }

inline const WONCrypt::SymmetricKey*
Session::GetKey() const
{ return mRefP->mKeyP; }

inline const WONAuth::AuthCertificateBase*
Session::GetCert() const
{ return mRefP->mCertP; }

inline const WONAuth::Auth1Certificate*
Session::GetAuth1Cert() const
{ 
	const WONAuth::AuthCertificateBase* aCertP = GetCert();
	return (aCertP && (aCertP->GetFamily() == WONAuth::AuthFamily1)) ? static_cast<const WONAuth::Auth1Certificate*>(aCertP) : NULL; 
}

inline unsigned long
Session::GetUserId() const
{ return (mRefP->mCertP ? mRefP->mCertP->GetUserId() : 0); }

/*
inline unsigned long
Session::GetCommunityId() const
{ return (mRefP->mCertP ? mRefP->mCertP->GetCommunityId() : 0); }

inline unsigned short
Session::GetTrustLevel() const
{ return (mRefP->mCertP ? mRefP->mCertP->GetTrustLevel() : 0); }
*/

inline bool
Session::IsRemote() const
{ return mRefP->mIsRemote; }

inline bool
Session::IsAuthenticated() const
{ return (mRefP->mCertP ? mRefP->mCertP->IsValid() : false); }

inline time_t
Session::GetLastAction() const
{ WONCommon::AutoCrit aCrit(mRefP->mCrit);  return mRefP->mLastAction; }

inline void
Session::Touch() const
{ WONCommon::AutoCrit aCrit(mRefP->mCrit);  time(&(mRefP->mLastAction)); }

inline unsigned short
Session::GetLastRecvSeq() const
{ WONCommon::AutoCrit aCrit(mRefP->mCrit);  return mRefP->mRecvSeq; }

inline unsigned short
Session::GetLastSendSeq() const
{ WONCommon::AutoCrit aCrit(mRefP->mCrit);  return mRefP->mSendSeq; }

inline unsigned short
Session::GetNextRecvSeq() const
{ WONCommon::AutoCrit aCrit(mRefP->mCrit);  return ++(mRefP->mRecvSeq); }

inline unsigned short
Session::GetNextSendSeq() const
{ WONCommon::AutoCrit aCrit(mRefP->mCrit);  return ++(mRefP->mSendSeq); }

inline unsigned short
Session::GetMsgsRecv() const
{ WONCommon::AutoCrit aCrit(mRefP->mCrit);  return mRefP->mRecvCt; }

inline unsigned short
Session::GetMsgsSent() const
{ WONCommon::AutoCrit aCrit(mRefP->mCrit);  return mRefP->mSendCt; }

inline unsigned short
Session::GetMsgsProc() const
{ WONCommon::AutoCrit aCrit(mRefP->mCrit);  return mRefP->mProcCt; }

inline void
Session::IncMsgsRecv() const
{ WONCommon::AutoCrit aCrit(mRefP->mCrit);  (mRefP->mRecvCt)++; }

inline void
Session::IncMsgsSent() const
{ WONCommon::AutoCrit aCrit(mRefP->mCrit);  (mRefP->mSendCt)++; }

inline void
Session::IncMsgsProc() const
{ WONCommon::AutoCrit aCrit(mRefP->mCrit);  (mRefP->mProcCt)++; }

};  // Namespace WONFramework


// Output operators
std::ostream&
operator<<(std::ostream& os, const WONAuth::EncryptAttributes& theAttrR);

inline std::ostream&
operator<<(std::ostream& os, const WONAuth::Session& theSessR)
{ theSessR.Dump(os);  return os; }

#endif