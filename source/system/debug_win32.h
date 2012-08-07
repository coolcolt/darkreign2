///////////////////////////////////////////////////////////////////////////////
//
// Copyright 1997-1999 Pandemic Studios, Dark Reign II
//
// Debugging Tools
//
// 1-DEC-1997
//


#ifndef __DEBUG_WIN32
#define __DEBUG_WIN32


///////////////////////////////////////////////////////////////////////////////
//
// Includes
//


///////////////////////////////////////////////////////////////////////////////
//
// NameSpace Debug
//
namespace Debug
{

  ///////////////////////////////////////////////////////////////////////////////
  //
  // Namespace Exception
  //
  namespace Exception
  {
    // Filter
    S32 STDCALL Filter(LPEXCEPTION_POINTERS ep);
  }
}

#endif