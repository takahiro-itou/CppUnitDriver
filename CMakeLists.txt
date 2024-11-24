
##----------------------------------------------------------------
##
##    モジュールの設定。
##

set(MODULE_DIR_NAME         "TestDriver")
set(MODULE_OUTPUT_NAME      "TestDriver")
set(MODULE_TITLE            "TestDriver")

set(inclib_source_dir       "${INCLUDE_SOURCE_DIR}/${MODULE_DIR_NAME}")
set(inclib_binary_dir       "${INCLUDE_BINARY_DIR}/${MODULE_DIR_NAME}")

##----------------------------------------------------------------
##
##    ソースファイルとヘッダファイルのリスト。
##

set(LIBRARY_SOURCE_FILES
        TestDriver.cpp
)

set(INCLIB_HEADER_FILES
)

##----------------------------------------------------------------
##
##    ビルドとインストールの設定。
##

Include (${COMMON_CMAKE_DIR}/BuildLibraryCommon.cmake)

set(test_driver_module  "${PROJECT_NAME}-${MODULE_TARGET_NAME}")
message(STATUS  "test_driver_module = ${test_driver_module}")

If ( TARGET  CPPUNIT::CPPUNIT )
    target_link_libraries(${test_driver_module}     CPPUNIT::CPPUNIT)
    message(STATUS  "Target CPPUNIT::CPPUNIT is defined.")
Else  ()
    target_compile_definitions(
        ${test_driver_module}   PUBLIC  HAVE_CPPUNIT=0
    )
    message(WARNING "Target CPPUNIT::CPPUNIT is NOT defined.")
EndIf ()
