add_executable(searching_test SearchingAlgoritmsTest.cpp)

target_link_libraries(searching_test
    PRIVATE
    searching
    unit_test_main
)

target_include_directories(searching_test
    PUBLIC
    ${PROJECT_SOURCE_DIR}/src/searching
)

add_dependencies(unit-tests searching_test)

add_test(unit-searching-test searching_test)

IF (WIN32)
    add_custom_command(
        TARGET searching_test
        POST_BUILD
        COMMAND ${CMAKE_COMMAND}
        ARGS -E copy_if_different "${PROJECT_SOURCE_DIR}/build/src/searching/libsearching.dll" "${CMAKE_CURRENT_BINARY_DIR}"
    )
ENDIF()
