///////////////////////////////////////////////////////////////////////////////
//
// Copyright 1999
// Matthew Versluys
//
// Win32 GUID
//


#ifndef __WIN32_GUID_H
#define __WIN32_GUID_H


///////////////////////////////////////////////////////////////////////////////
//
// Includes
//
#include "win32.h"


///////////////////////////////////////////////////////////////////////////////
//
// NameSpace Win32
//
namespace Win32
{

  ///////////////////////////////////////////////////////////////////////////////
  //
  // NameSpace GUID
  //
  namespace GUID
  {
    // Convert a GUID to text
    const char * GUID2Text(const ::GUID &guid);

    // Convert text to a GUID
    const ::GUID & Text2GUID(const char *text);
  }

}

#endif