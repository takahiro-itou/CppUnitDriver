
##----------------------------------------------------------------
##
##    モジュールの設定。
##

set(module_title        "TestDriver")

Include (${common_cmake_dir}/BuildCommon/ConfigModule.cmake)
Include (${common_cmake_dir}/BuildCommon/ConfigTarget.cmake)

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

Include (${common_cmake_dir}/BuildCommon/BuildLib.cmake)
Include (${common_cmake_dir}/BuildCommon/Install.cmake)

set(test_driver_module  "${project_module_target}")
message(STATUS  "test_driver_module = ${test_driver_module}")

If ( TARGET  TestDriver::CppUnit )
    target_link_libraries(${test_driver_module}     TestDriver::CppUnit)
    message(STATUS  "Target TestDriver::CppUnit is defined.")
Else  ()
    target_compile_definitions(
        ${test_driver_module}   PUBLIC  HAVE_CPPUNIT=0
    )
    message(WARNING "Target TestDriver::CppUnit is NOT defined.")
EndIf ()


##----------------------------------------------------------------
##
##    インクルードパスの設定。
##

target_include_directories(
    ${test_driver_module}  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_include_directories(
    ${test_driver_module}  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)
