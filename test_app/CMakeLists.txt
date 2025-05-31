configure_file(${CMAKE_SOURCE_DIR}/cool_lib.h
        ${CMAKE_BINARY_DIR}/cool_lib/cool_lib.h
        COPYONLY)

add_executable(cool_test app.cpp)
target_link_libraries(cool_test PRIVATE cool_lib)
target_include_directories(cool_test PRIVATE ${CMAKE_BINARY_DIR})
set_target_properties(cool_test PROPERTIES
        OUTPUT_NAME "cool_test"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        VERSION "${CMAKE_PROJECT_VERSION_MAJOR}.${CMAKE_PROJECT_VERSION_MINOR}.${CMAKE_PROJECT_VERSION_PATCH}"
        SOVERSION "${CMAKE_PROJECT_VERSION_MAJOR}"
)