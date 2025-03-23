
##----------------------------------------------------------------
##
##    モジュールの設定。
##

set(target_testee_library   "${module_title}")

set(driver_source_dir       "${libtop_source_dir}/Tests")
set(driver_binary_dir       "${libtop_binary_dir}/Tests")

Include (${common_cmake_dir}/BuildCommon/ConfigTarget.cmake)


##----------------------------------------------------------------
##
##    テストの共通設定。
##

set(tester_link_libraries
        ${project_target_prefix}${target_testee_library}
        ${project_target_prefix}TestDriver
)

message("tester_link_libraries = ${tester_link_libraries}")
include_directories(${CMAKE_CURRENT_BINARY_DIR})
link_libraries     (${tester_link_libraries})


##----------------------------------------------------------------
##
##    テストの個別設定。
##

Include (TestConf.cmake)


##----------------------------------------------------------------
##
##    設定を書き込んだファイルを生成。
##

set(top_srcdir      "${PROJECT_SOURCE_DIR}")
set(top_builddir    "${PROJECT_BINARY_DIR}")

If ( EXISTS  ${CMAKE_CURRENT_SOURCE_DIR}/TestConf.h.in )
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/TestConf.h.in"
        "${CMAKE_CURRENT_BINARY_DIR}/TestConf.h"
        @ONLY
    )
EndIf ()
