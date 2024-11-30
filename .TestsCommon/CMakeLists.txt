
##----------------------------------------------------------------
##
##    モジュールの設定。
##

set(TARGET_TESTEE_LIBRARY   "${module_title}")

set(DRIVER_SOURCE_DIR       "${libtop_source_dir}/Tests")
set(DRIVER_BINARY_DIR       "${libtop_binary_dir}/Tests")

Include (${common_cmake_dir}/ConfigTarget.cmake)

##----------------------------------------------------------------
##
##    テストの設定。
##

set(tester_link_libraries
        ${PROJECT_NAME}-${TARGET_TESTEE_LIBRARY}
        ${project_target_prefix}TestDriver
)

include_directories(${PROJECT_SOURCE_DIR}/Lib/Tests)
link_libraries     (${tester_link_libraries})

Include (TestConf.cmake)
