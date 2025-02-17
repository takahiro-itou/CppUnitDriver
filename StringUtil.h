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

template <typename T>
typename std::enable_if<!std::is_enum<T>::value, std::string>::type
toString(const T &x)
{
    std::stringstream   ss;
    ss  <<  x;

    return  ss.str();
}

template <typename T>
typename std::enable_if<std::is_enum<T>::value, std::string>::type
toString(const T &x)
{
    std::stringstream   ss;
    ss  <<  static_cast<int>(x);

    return  ss.str();
}

#endif

