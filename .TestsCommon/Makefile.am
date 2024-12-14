
##
##    ライブラリの単体テスト。
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

target_testee_library       =

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
##    Append Test Configurations.
##

dist_noinst_data_files      +=  CMakeLists.txt  TestConf.cmake
dist_noinst_header_files    +=
extra_test_drivers          +=
library_test_drivers        +=  ${driver_binary_dir}/libTestDriver.a
source_test_drivers         +=

##
##    Compile and Link Options.
##

test_cppflags_common        +=
test_ldflags_common         +=

test_cppflags_xunit         =  @cppunit_cppflags@
test_cflags_xunit           =  @cppunit_cflags@
test_cxxflags_xunit         =  @cppunit_cxxflags@
test_ldflags_xunit          =  @cppunit_ldflags@

if  AMCNF_CPPUNIT_ENABLED
test_link_ldadd_xunit       =  @cppunit_link_ldadd@
else
test_link_ldadd_xunit       =
endif

AM_CPPFLAGS         =  \
        -I${testee_source_dir}      \
        -I${inctop_source_dir}      \
        -I${libtop_source_dir}      \
        -I${driver_source_dir}      \
        -I${driver_binary_dir}      \
        ${test_cppflags_common}     \
        ${test_cppflags_xunit}

AM_CFLAGS           =  ${test_cflags_xunit}
AM_CXXFLAGS         =  ${test_cxxflags_xunit}
AM_LDFLAGS          =  \
        -L${libtop_binary_dir}  \
        ${test_ldflags_common}  \
        ${test_ldflags_xunit}

LDADD               =  \
        ${target_testee_library}  \
        ${library_test_drivers}   \
        ${test_link_ldadd_xunit}

##
##    List of Installs.
##

check_PROGRAMS      =  ${TESTS}

##
##    Include Common Install Settings.
##

include  $(top_srcdir)/.M4/BuildCommon/Install.inc
