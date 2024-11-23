
##
##    ライブラリの単体テスト。
##

##
##    List of Directories.
##

include  $(top_srcdir)/.M4/Makefile.DirList.inc

driver_source_dir       =  ${LIBTOP_SOURCE_DIR}/Tests
driver_binary_dir       =  ${LIBTOP_BINARY_DIR}/Tests
testee_source_dir       =  @srcdir@/..
testee_binary_dir       =  ..

##
##    Initialize Test Configurations.
##

TARGET_TESTEE_LIBRARY       =

DIST_NOINST_DATA_FILES      =
DIST_NOINST_HEADER_FILES    =
extra_test_drivers          =
library_test_drivers        =
source_test_drivers         =

TEST_CPPFLAGS_COMMON        =
test_ldflags_common         =

##
##    Test Configurations.
##

include  ${srcdir}/TestConf.mak

##
##    Append Test Configurations.
##

DIST_NOINST_DATA_FILES      +=  CMakeLists.txt  TestConf.cmake
DIST_NOINST_HEADER_FILES    +=
extra_test_drivers          +=
library_test_drivers        +=  ${driver_binary_dir}/libTestDriver.a
source_test_drivers         +=

##
##    Compile and Link Options.
##

TEST_CPPFLAGS_COMMON        +=
test_ldflags_common         +=

test_cppflags_xunit         =  @CPPUNIT_CPPFLAGS@
TEST_CFLAGS_XUNIT           =  @CPPUNIT_CFLAGS@
TEST_CXXFLAGS_XUNIT         =  @CPPUNIT_CXXFLAGS@
TEST_LDFLAGS_XUNIT          =  @CPPUNIT_LDFLAGS@

if  AMCNF_CPPUNIT_ENABLED
TEST_LINK_LDADD_XUNIT       =  @CPPUNIT_LINK_LDADD@
else
TEST_LINK_LDADD_XUNIT       =
endif

AM_CPPFLAGS         =  \
        -I${testee_source_dir}      \
        -I${INCTOP_SOURCE_DIR}      \
        -I${LIBTOP_SOURCE_DIR}      \
        -I${driver_source_dir}      \
        -I${driver_binary_dir}      \
        ${TEST_CPPFLAGS_COMMON}     \
        ${test_cppflags_xunit}

AM_CFLAGS           =  ${TEST_CFLAGS_XUNIT}
AM_CXXFLAGS         =  ${TEST_CXXFLAGS_XUNIT}
AM_LDFLAGS          =  \
        -L${LIBTOP_BINARY_DIR}  \
        ${test_ldflags_common}  \
        ${TEST_LDFLAGS_XUNIT}

LDADD               =  \
        ${TARGET_TESTEE_LIBRARY}  \
        ${library_test_drivers}   \
        ${TEST_LINK_LDADD_XUNIT}

##
##    List of Installs.
##

check_PROGRAMS      =  ${TESTS}

##
##    Include Common Install Settings.
##

include  ${top_srcdir}/.M4/Makefile.Install.inc
