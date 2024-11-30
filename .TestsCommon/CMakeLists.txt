
##----------------------------------------------------------------
##
##    モジュールの設定。
##

set(target_testee_library   "${module_title}")

set(DRIVER_SOURCE_DIR       "${libtop_source_dir}/Tests")
set(DRIVER_BINARY_DIR       "${libtop_binary_dir}/Tests")

Include (${common_cmake_dir}/ConfigTarget.cmake)

##----------------------------------------------------------------
##
##    テストの共通設定。
##

set(tester_link_libraries
        ${project_target_prefix}${target_testee_library}
        ${project_target_prefix}TestDriver
)

include_directories(${PROJECT_SOURCE_DIR}/Lib/Tests)
link_libraries     (${tester_link_libraries})

##----------------------------------------------------------------
##
##    テストの個別設定。
##

Include (TestConf.cmake)
