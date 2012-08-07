#ifndef ROUTINGMESSAGES_H
#define ROUTINGMESSAGES_H

// Shortcut header to include and use all of the Routing Server messages.

// Include the messages
#include <msg/BadMsgException.h>
#include <msg/TMessage.h>
#include <msg/MServiceTypes.h>
#include <msg/ServerStatus.h>
#include <msg/Comm/MMsgTypesComm.h>
#include <msg/Routing/MMsgTypesRouting.h>
#include <msg/Routing/MMsgRoutingAcceptClient.h>
#include <msg/Routing/MMsgRoutingAddToGroup.h>
#include <msg/Routing/MMsgRoutingAddSuccessor.h>
#include <msg/Routing/MMsgRoutingBanClient.h>
#include <msg/Routing/MMsgRoutingBaseDataObject.h>
#include <msg/Routing/MMsgRoutingBecomeModerator.h>
#include <msg/Routing/MMsgRoutingBootClient.h>
#include <msg/Routing/MMsgRoutingClientBooted.h>
#include <msg/Routing/MMsgRoutingClientChange.h>
#include <msg/Routing/MMsgRoutingCloseReg.h>
#include <msg/Routing/MMsgRoutingCreateDataObject.h>
#include <msg/Routing/MMsgRoutingCreateGroup.h>
#include <msg/Routing/MMsgRoutingDeleteDataObject.h>
#include <msg/Routing/MMsgRoutingDeleteGroup.h>
#include <msg/Routing/MMsgRoutingDisconnectClient.h>
#include <msg/Routing/MMsgRoutingGetClientList.h>
#include <msg/Routing/MMsgRoutingGetGroupList.h>
#include <msg/Routing/MMsgRoutingGetSimpleClientL.h>
#include <msg/Routing/MMsgRoutingGroupChange.h>
#include <msg/Routing/MMsgRoutingGrpSpectatorCnt.h>
#include <msg/Routing/MMsgRoutingHostChange.h>
#include <msg/Routing/MMsgRoutingInviteClient.h>
#include <msg/Routing/MMsgRoutingKeepAlive.h>
#include <msg/Routing/MMsgRoutingModifyDataObject.h>
#include <msg/Routing/MMsgRoutingMuteClient.h>
#include <msg/Routing/MMsgRoutingOpenRegistration.h>
#include <msg/Routing/MMsgRoutingPeerChat.h>
#include <msg/Routing/MMsgRoutingPeerData.h>
#include <msg/Routing/MMsgRoutingPeerDataMultiple.h>
#include <msg/Routing/MMsgRoutingReadDataObject.h>
#include <msg/Routing/MMsgRoutingReadDataObjectR.h>
#include <msg/Routing/MMsgRoutingReconnectClient.h>
#include <msg/Routing/MMsgRoutingRegisterClient.h>
#include <msg/Routing/MMsgRoutingRemoveFromGroup.h>
#include <msg/Routing/MMsgRoutingRemoveSuccessor.h>
#include <msg/Routing/MMsgRoutingRenewDataObject.h>
#include <msg/Routing/MMsgRoutingReplaceDataObj.h>
#include <msg/Routing/MMsgRoutingSendChat.h>
#include <msg/Routing/MMsgRoutingSendData.h>
#include <msg/Routing/MMsgRoutingSendDataBrdcst.h>
#include <msg/Routing/MMsgRoutingSendDataMultiple.h>
#include <msg/Routing/MMsgRoutingSetPassword.h>
#include <msg/Routing/MMsgRoutingSpectatorCount.h>
#include <msg/Routing/MMsgRoutingStatusReply.h>
#include <msg/Routing/MMsgRoutingSubDataObject.h>
#include <msg/Routing/MMsgRoutingUnsubDataObject.h>
#include <msg/Chat/TMsgChat.h>
#include <msg/Comm/MMsgCommGetNumUsers.h>
#include <msg/Comm/MMsgCommIsUserPresent.h>
#include <msg/User/Polling/SMsgUsrGetPolledUserList.h>
#include <msg/User/Polling/SMsgUsrGetPolledUserListReply.h>
#include <msg/User/Reconnects/SMsgUsrReconnectDataSource.h>
#include <msg/User/Subscription/SMsgUsrPushedUserList.h>
#include <msg/User/Subscription/SMsgUsrSubscribeToUserList.h>
#include <msg/User/SelfRegistration/Replies/SMsgUsrRegisterDataSourceReply.h>
#include <msg/User/SelfRegistration/Requests/SMsgUsrRegisterDataSource.h>
#include <msg/User/SelfRegistration/Requests/SMsgUsrRemoveDataSource.h>
#include <msg/User/SelfRegistration/Requests/SMsgUsrReconnectSelfDataSource.h>

// Use the messages
using WONMsg::BadMsgException;
using WONMsg::TMessage;
using WONMsg::MiniMessage;
using WONMsg::ServerStatus;
using WONMsg::MMsgRoutingAcceptClient;
using WONMsg::MMsgRoutingAcceptClientReply;
using WONMsg::MMsgRoutingAddToGroup;
using WONMsg::MMsgRoutingAddSuccessor;
using WONMsg::MMsgRoutingBanClient;
using WONMsg::MMsgRoutingBaseDataObject; // base class for Create, Delete, and ModifyDataObject messages
using WONMsg::MMsgRoutingBecomeModerator;
using WONMsg::MMsgRoutingBootClient;
using WONMsg::MMsgRoutingClientBooted;
using WONMsg::MMsgRoutingClientChange;
using WONMsg::MMsgRoutingClientChangeEx;
using WONMsg::MMsgRoutingCloseRegistration;
using WONMsg::MMsgRoutingCreateDataObject;
using WONMsg::MMsgRoutingCreateGroup;
using WONMsg::MMsgRoutingCreateGroupReply;
using WONMsg::MMsgRoutingDeleteDataObject;
using WONMsg::MMsgRoutingDeleteGroup;
using WONMsg::MMsgRoutingDisconnectClient;
using WONMsg::MMsgRoutingGetClientInfo;
using WONMsg::MMsgRoutingGetClientList;
using WONMsg::MMsgRoutingGetClientListReply;
using WONMsg::MMsgRoutingGetGroupList;
using WONMsg::MMsgRoutingGetGroupListReply;
using WONMsg::MMsgRoutingGetMembersOfGroup;
using WONMsg::MMsgRoutingGetSimpleClientList;
using WONMsg::MMsgRoutingGetSimpleClientListReply;
using WONMsg::MMsgRoutingGroupChange;
using WONMsg::MMsgRoutingGroupChangeEx;
using WONMsg::MMsgRoutingGroupSpectatorCount;
using WONMsg::MMsgRoutingHostChange;
using WONMsg::MMsgRoutingInviteClient;
using WONMsg::MMsgRoutingKeepAlive;
using WONMsg::MMsgRoutingModifyDataObject;
using WONMsg::MMsgRoutingMuteClient;
using WONMsg::MMsgRoutingOpenRegistration;
using WONMsg::MMsgRoutingPeerChat;
using WONMsg::MMsgRoutingPeerData;
using WONMsg::MMsgRoutingPeerDataMultiple;
using WONMsg::MMsgRoutingReadDataObject;
using WONMsg::MMsgRoutingReadDataObjectReply;
using WONMsg::MMsgRoutingReconnectClient;
using WONMsg::MMsgRoutingRegisterClient;
using WONMsg::MMsgRoutingRegisterClientReply;
using WONMsg::MMsgRoutingRemoveFromGroup;
using WONMsg::MMsgRoutingRemoveSuccessor;
using WONMsg::MMsgRoutingRenewDataObject;
using WONMsg::MMsgRoutingReplaceDataObject;
using WONMsg::MMsgRoutingSendChat;
using WONMsg::MMsgRoutingSendData;
using WONMsg::MMsgRoutingSendDataBroadcast;
using WONMsg::MMsgRoutingSendDataMultiple;
using WONMsg::MMsgRoutingSetPassword;
using WONMsg::MMsgRoutingSpectatorCount;
using WONMsg::MMsgRoutingStatusReply;
using WONMsg::MMsgRoutingSubscribeDataObject;
using WONMsg::MMsgRoutingUnsubscribeDataObject;

using WONMsg::TMsgChat_UserJoin;
using WONMsg::TMsgChat_UserJoinReply;
using WONMsg::TMsgChat_UserJoined;
using WONMsg::TMsgChat_UsersHere;
using WONMsg::TMsgChat_UserPresent;
using WONMsg::TMsgChat_UserPresentReply;
using WONMsg::TMsgChat_UserLeft;
using WONMsg::TMsgChat_ChatDataMessage;
using WONMsg::TMsgChat_SimpleChatDataMessage;
using WONMsg::TMsgChat_UserDataMessage;
using WONMsg::TMsgChat_ReqUserData;
using WONMsg::TMsgChat_RemoveUserData;
using WONMsg::TMsgChat_UserDataMessageReply;
using WONMsg::TMsgChat_RemoveUserDataReply;
using WONMsg::TMsgChat_UnsubUserData;
using WONMsg::TMsgChat_ChangeName;
using WONMsg::TMsgChat_ChangeNameReply;
using WONMsg::TMsgChat_UserLurk;
using WONMsg::TMsgChat_UserLurkReply;
using WONMsg::TMsgChat_SubscribeUserData;
using WONMsg::TMsgChat_LurkerCount;

using WONMsg::MMsgCommGetNumUsers;
using WONMsg::MMsgCommGetNumUsersReply;
using WONMsg::MMsgCommIsUserPresent;
using WONMsg::MMsgCommIsUserPresentReply;

using WONMsg::SMsgUsrGetPolledUserList;
using WONMsg::SMsgUsrGetPolledUserListReply;
using WONMsg::SMsgUsrPushedUserList;
using WONMsg::SMsgUsrReconnectDataSource;
using WONMsg::SMsgUsrReconnectSelfDataSource;
using WONMsg::SMsgUsrRegisterDataSource;
using WONMsg::SMsgUsrRegisterDataSourceReply;
using WONMsg::SMsgUsrRemoveDataSource;
using WONMsg::SMsgUsrSubscribeToUserList;

#endif // ROUTINGMESSAGES_H