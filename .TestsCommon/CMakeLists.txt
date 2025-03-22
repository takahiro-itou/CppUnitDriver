
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
include_directories(${libtop_source_dir}/Tests)
include_directories(${libtop_binary_dir}/Tests)
link_libraries     (${tester_link_libraries})

##----------------------------------------------------------------
##
##    テストの個別設定。
##

Include (TestConf.cmake)
