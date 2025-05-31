cmake_minimum_required(VERSION 3.13)
message(STATUS "Initiating compile using CMake ${CMAKE_VERSION}")

project(cool_lib VERSION "0.0.1" DESCRIPTION "cool_lib")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# gather our files for compilation
file(GLOB project_files
    "*.h"
    "*.cpp"
    "lib/*.h"
    "lib/*.cpp"
)

# this creates the .so (shared library)
add_library(cool_lib SHARED ${project_files})

# compile the test app too
add_subdirectory(test_app)

set_target_properties(cool_lib PROPERTIES
        OUTPUT_NAME "cool_lib"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        VERSION "${CMAKE_PROJECT_VERSION_MAJOR}.${CMAKE_PROJECT_VERSION_MINOR}.${CMAKE_PROJECT_VERSION_PATCH}"
        SOVERSION "${CMAKE_PROJECT_VERSION_MAJOR}"
)

## install our public header, for consumption by other software
install(FILES cool_lib.h DESTINATION include/cool_lib/)

## Create a CMake package
target_include_directories(cool_lib
        PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        PUBLIC $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(TARGETS cool_lib
        EXPORT cool_libTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT cool_libTargets
        FILE cool_libTargets.cmake
        NAMESPACE cool_lib::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cool_lib
)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/cool_libConfig.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cool_lib
)

write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/cool_libConfigVersion.cmake"
        VERSION "${CMAKE_PROJECT_VERSION}"
        COMPATIBILITY AnyNewerVersion
)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/cool_libConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/cool_libConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cool_lib
)