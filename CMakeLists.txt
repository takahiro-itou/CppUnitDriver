
##----------------------------------------------------------------
##
##    モジュールの設定。
##

set(module_title        "TestDriver")

Include (${common_cmake_dir}/ConfigModule.cmake)

##----------------------------------------------------------------
##
##    ソースファイルとヘッダファイルのリスト。
##

set(library_source_files
        TestDriver.cpp
)

set(inclib_header_files
)

##----------------------------------------------------------------
##
##    ビルドとインストールの設定。
##

Include (${common_cmake_dir}/BuildLibraryCommon.cmake)

set(test_driver_module  "${project_module_target}")
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
