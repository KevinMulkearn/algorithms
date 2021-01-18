add_executable(main_test main.cpp)

target_link_libraries(main_test
    PRIVATE
    sorting
    timing
)

target_include_directories(main_test
    PUBLIC
    ${PROJECT_SOURCE_DIR}/src/sorting
    ${PROJECT_SOURCE_DIR}/src/timing
)
