////////////////////////////////////////////////////////////////////////////////
//
// StyxNet
//
// Copyright 1999-2000
// Matthew Versluys
//


////////////////////////////////////////////////////////////////////////////////
//
// Includes
//
#include "styxnet_private.h"
#include "styxnet_server_private.h"


////////////////////////////////////////////////////////////////////////////////
//
// NameSpace StyxNet
//
namespace StyxNet
{

  ////////////////////////////////////////////////////////////////////////////////
  //
  // Class Server::Item
  //


  //
  // Item::Item
  //
  Server::Item::Item(CRC user, Packet &packet)
  : user(user),
    packet(packet)
  {
  }


  //
  // Item::~Item
  //
  Server::Item::~Item()
  {
    // Delete the packet
    delete (&packet);
  }

}

