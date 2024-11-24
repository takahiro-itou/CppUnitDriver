
##----------------------------------------------------------------
##
##    モジュールの設定。
##

set(TARGET_TESTEE_LIBRARY   "${MODULE_TITLE}")

set(DRIVER_SOURCE_DIR       "${libtop_source_dir}/Tests")
set(DRIVER_BINARY_DIR       "${libtop_binary_dir}/Tests")

##----------------------------------------------------------------
##
##    テストの設定。
##

set(tester_link_libraries
        ${PROJECT_NAME}-${TARGET_TESTEE_LIBRARY}
        ${PROJECT_NAME}-TestDriver
)

include_directories(${PROJECT_SOURCE_DIR}/Lib/Tests)
link_libraries     (${tester_link_libraries})

Include (TestConf.cmake)
