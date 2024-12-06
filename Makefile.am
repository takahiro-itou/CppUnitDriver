
##
##    ライブラリの単体テストドライバ。
##

##
##    List of Directories.
##

include  $(top_srcdir)/.M4/BuildCommon/DirList.inc

driver_source_dir       =  ${libtop_source_dir}/Tests
driver_binary_dir       =  ${libtop_binary_dir}/Tests
testee_source_dir       =  @srcdir@/..
testee_binary_dir       =  ..

##
##    Initialize Test Configurations.
##

dist_noinst_data_files      =
dist_noinst_header_files    =
extra_test_drivers          =
library_test_drivers        =
source_test_drivers         =

test_cppflags_common        =
test_ldflags_common         =

##
##    Test Configurations.
##

include  $(srcdir)/TestConf.mak

##
##    List of Source and Header Files.
##

dist_noinst_data_files      +=  CMakeLists.txt
dist_noinst_header_files    +=  TestDriver.h
extra_test_drivers          +=
library_test_drivers        +=  libTestDriver.a
source_test_drivers         +=  TestDriver.cpp

##
##    Compile and Link Options.
##

test_cppflags_common        +=
test_ldflags_common         +=

test_cppflags_xunit         =  @CPPUNIT_CPPFLAGS@
test_cflags_xunit           =  @CPPUNIT_CFLAGS@
test_cxxflags_xunit         =  @CPPUNIT_CXXFLAGS@
test_ldflags_xunit          =  @CPPUNIT_LDFLAGS@

if  AMCNF_CPPUNIT_ENABLED
test_link_ldadd_xunit       =  @CPPUNIT_LINK_LDADD@
else
test_link_ldadd_xunit       =
endif

AM_CPPFLAGS         =  \
        -I${testee_source_dir}      \
        -I${inctop_source_dir}      \
        -I${driver_source_dir}      \
        -I${driver_binary_dir}      \
        ${test_cppflags_common}     \
        ${test_cppflags_xunit}

AM_CFLAGS           =  ${test_cflags_xunit}
AM_CXXFLAGS         =  ${test_cxxflags_xunit}
AM_LDFLAGS          =  \
        ${test_ldflags_common}   \
        ${test_ldflags_xunit}

LDADD               =  \
        ${test_link_ldadd_xunit}

##
##    List of Installs.
##

check_PROGRAMS      =  ${TESTS}
noinst_LIBRARIES    =  ${library_test_drivers}

##
##    Include Common Install Settings.
##

include  $(top_srcdir)/.M4/BuildCommon/Install.inc

##
##    Build of Test Drivers.
##

libTestDriver_a_SOURCES     =  ${source_test_drivers}
