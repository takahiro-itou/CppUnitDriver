﻿//  -*-  coding: utf-8-with-signature;  mode: c++  -*-  //
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
**      An Interface of Test Driver.
**
**      @file       TestDriver.h
**/

#if !defined( CPPUNITDRIVER_TESTS_INCLUDED_TEST_DRIVER_H )
#    define   CPPUNITDRIVER_TESTS_INCLUDED_TEST_DRIVER_H


//----------------------------------------------------------------
/**   単体テストを起動するエントリポイント。
**
**  @param [in] argc
**  @param [in] argv
**  @return
**/

int
executeCppUnitTests(
        int     argc,
        char *  argv[]);


//========================================================================

#if ( HAVE_CPPUNIT )

#    include    <cppunit/extensions/HelperMacros.h>

using   namespace   CPPUNIT_NS;

#else   //  if ! ( HAVE_CPPUNIT )

#include    <iostream>
#include    <stdlib.h>

#if !defined( CPPUNITDRIVER_TESTS_INCLUDED_STRING_UTIL_H )
#    include    "StringUtil.h"
#endif

class   TestFixture
{
public:
    TestFixture();
    virtual  ~TestFixture();

    virtual  void   setUp();
    virtual  void   tearDown();
};

#define     CPPUNIT_TEST_SUITE(classname)       \
public:                                         \
    classname() {                               \
        executeTests();                         \
   }                                            \
protected:                                      \
    void  executeTests()  {

#define     CPPUNIT_TEST(funcname)              \
    funcname()

#define     CPPUNIT_TEST_SUITE_END()            \
    }                                           \
    static  void  run()

#define     CPPUNIT_TEST_SUITE_REGISTRATION(classname)  \
    classname   g_ ## classname ## _Instance;

template  <typename  T>
void  assertEqual(
        const  T  &     vExp,
        const  T  &     vAct,
        const  char  *  szFile,
        const  int      nLine)
{
    if ( vExp != vAct ) {
        std::cerr   <<  "\nEquality Assertion Failed."
                    <<  "\n  Expected : "   <<  toString(vExp)
                    <<  "\n  Actual   : "   <<  toString(vAct)
                    <<  std::endl;
        exit ( 1 );
    }
    return;
}

#define     CPPUNIT_ASSERT_EQUAL(exp, act)      \
    assertEqual(exp,  act,  __FILE__,  __LINE__)

#endif  //  ! ( HAVE_CPPUNIT )

#endif
