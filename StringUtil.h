//  -*-  coding: utf-8-with-signature;  mode: c++  -*-  //
/*************************************************************************
**                                                                      **
**                      ---  Unit Test Driver  ---                      **
**                                                                      **
**          Copyright (C), 2016-2025, Takahiro Itou                     **
**          All Rights Reserved.                                        **
**                                                                      **
**          License: (See COPYING or LICENSE files)                     **
**          GNU Affero General Public License (AGPL) version 3,         **
**          or (at your option) any later version.                      **
**                                                                      **
*************************************************************************/

/**
**      An Interface of String Util.
**
**      @file       StringUtil.h
**/

#if !defined( CPPUNITDRIVER_TESTS_INCLUDED_STRING_UTIL_H )
#    define   CPPUNITDRIVER_TESTS_INCLUDED_STRING_UTIL_H

#if !defined( CPPUNITDRIVER_SYS_INCLUDED_SSTREAM )
#    include    <sstream>
#    define   CPPUNITDRIVER_SYS_INCLUDED_SSTREAM
#endif

template  <typename  T>
typename  std::enable_if<!std::is_enum<T>::value, std::string>::type
toString(const T &x)
{
    std::stringstream   ss;
    ss  <<  x;

    return  ss.str();
}

template  <typename  T>
typename  std::enable_if<std::is_enum<T>::value, std::string>::type
toString(const T &x)
{
    typedef     typename  std::underlying_type<T>::type     base_type;
    std::stringstream   ss;
    ss  <<  static_cast<base_type>(x);

    return  ss.str();
}

#endif

