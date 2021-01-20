add_executable(sorting_test SortingAlgoritmsTest.cpp)

target_link_libraries(sorting_test
    PRIVATE
    sorting
    unit_test_main
)

target_include_directories(sorting_test
    PUBLIC
    ${PROJECT_SOURCE_DIR}/src/sorting
)

add_dependencies(unit-tests sorting_test)

add_test(unit-sorting-test sorting_test)

IF (WIN32)
    add_custom_command(
        TARGET sorting_test
        POST_BUILD
        COMMAND ${CMAKE_COMMAND}
        ARGS -E copy_if_different "${PROJECT_SOURCE_DIR}/build/src/sorting/libsorting.dll" "${CMAKE_CURRENT_BINARY_DIR}"
    )
ENDIF()
