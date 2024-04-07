cmake_minimum_required(VERSION 3.27.0)

project(fcppt)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

list(APPEND FCPPT_UTILS_CLANG_TIDY_ADDITIONAL_CHECKS
     "-cppcoreguidelines-avoid-magic-numbers" "-readability-magic-numbers")

set(FCPPT_UTILS_CLANG_TIDY_WHITELIST "fcppt")

include(FcpptCMakeUtils)

include(FcpptSymbol)

set(FCPPT_MAJOR_VERSION 4)

set(FCPPT_MINOR_VERSION 5)

set(FCPPT_MICRO_VERSION 0)

set(FCPPT_VERSION
    "${FCPPT_MAJOR_VERSION}.${FCPPT_MINOR_VERSION}.${FCPPT_MICRO_VERSION}")

fcppt_utils_handle_so_version(FCPPT_SO_VERSION FCPPT_USED_SO_VERSION
                              "${FCPPT_MAJOR_VERSION}.${FCPPT_MINOR_VERSION}")

math(
  EXPR
  FCPPT_INT_VERSION
  "${FCPPT_MAJOR_VERSION} * 1000000 + ${FCPPT_MINOR_VERSION} * 1000 + ${FCPPT_MICRO_VERSION}"
)

include(CheckCXXSourceCompiles)

if(WIN32)
  set(ENABLE_NARROW_STRING_DEFAULT OFF)
else()
  set(ENABLE_NARROW_STRING_DEFAULT ON)
endif()

option(ENABLE_NARROW_STRING
       "Build fcppt with std::string instead of std::wstring"
       ${ENABLE_NARROW_STRING_DEFAULT})

find_package(Boost 1.47.0)

find_package(Catch2 CONFIG)

option(ENABLE_BOOST "Build the boost support library" ${Boost_FOUND})

option(ENABLE_CATCH "Build the Catch support library" ${Catch2_FOUND})

option(ENABLE_EXAMPLES "Build the examples" ON)

option(ENABLE_TEST "Build the tests" OFF)

option(ENABLE_THREADS "Use std::mutex in fcppt.log" ON)

set(SIGNALS_BENCHMARK_BACKEND
    "fcppt"
    CACHE
      STRING
      "Which backend to use for the signal benchmark example {fcppt, boostsignals2}"
)

fcppt_utils_static_shared()

set(FCPPT_NARROW_STRING ${ENABLE_NARROW_STRING})

if(CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP)
  check_cxx_source_compiles(
    "#include <cxxabi.h>
    #include <cstdlib>
    int main() { int status; char *name =
    abi::__cxa_demangle(typeid(int).name(),0,0,&status); std::free(name); }"
    FCPPT_HAVE_GCC_DEMANGLE)
endif()

configure_file(${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake/version.hpp.in
               ${FCPPT_UTILS_PROJECT_BINARY_DIR}/include/fcppt/version.hpp)

configure_file(
  ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake/public_config.hpp.in
  ${FCPPT_UTILS_PROJECT_BINARY_DIR}/include/fcppt/public_config.hpp)

configure_file(
  ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake/private_config.hpp.in
  ${FCPPT_UTILS_PROJECT_BINARY_DIR}/impl/include/fcppt/impl/private_config.hpp)

include(CMakeParseArguments)

set(FCPPT_STATIC_LINK_FLAG FCPPT_STATIC_LINK)

# Helper function to create an fcppt library.
function(make_fcppt_library_base targetname cur_files)
  set(option_args HAS_IMPL_DIR)

  set(single_args VARIANT)

  set(multi_args
      FCPPT_DEPS
      TRANSITIVE_FCPPT_DEPS
      DEPS
      TRANSITIVE_DEPS
      IMPORTED_DEPS
      TRANSITIVE_IMPORTED_DEPS
      INCLUDE_DIRS
      SYSTEM_INCLUDE_DIRS
      COMPILE_DEFINITIONS
      TRANSITIVE_COMPILE_DEFINITIONS
      HEADER_ONLY_EXCEPTIONS)

  cmake_parse_arguments("" "${HAS_IMPL_DIR}" "${single_args}" "${multi_args}"
                        ${ARGN})

  fcppt_utils_append_source_dir_and_make_groups(
    "${cur_files}" FCPPT_${targetname}_FILES HEADER_ONLY_EXCEPTIONS
    ${_HEADER_ONLY_EXCEPTIONS})

  if(${_VARIANT} STREQUAL INTERFACE)
    add_library(${targetname} ${_VARIANT})
  else()
    add_library(${targetname} ${_VARIANT} ${FCPPT_${targetname}_FILES})
  endif()

  if(NOT ${_VARIANT} STREQUAL INTERFACE)
    set_target_properties(${targetname} PROPERTIES VERSION
                                                   ${FCPPT_USED_SO_VERSION})

    fcppt_utils_set_target_compiler_flags(${targetname})

    set_target_properties(${targetname} PROPERTIES FOLDER fcppt)
  endif()

  fcppt_utils_interface_static_link(${targetname} ${_VARIANT}
                                    ${FCPPT_STATIC_LINK_FLAG})

  set(public_includes
      "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
      "$<BUILD_INTERFACE:${FCPPT_UTILS_PROJECT_BINARY_DIR}/include>"
      ${_INCLUDE_DIRS})

  if(NOT ${_VARIANT} STREQUAL INTERFACE)
    target_include_directories(
      ${targetname}
      PUBLIC ${public_includes}
      PRIVATE
        "$<BUILD_INTERFACE:${FCPPT_UTILS_PROJECT_BINARY_DIR}/impl/include>")

    target_include_directories(${targetname} SYSTEM
                               PRIVATE ${_SYSTEM_INCLUDE_DIRS})

    target_compile_definitions(${targetname} PRIVATE ${_COMPILE_DEFINITIONS})

    fcppt_utils_link_imported_targets(${targetname} PRIVATE ${_IMPORTED_DEPS})

    if(${_HAS_IMPL_DIR})
      target_include_directories(
        ${targetname}
        PRIVATE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/impl/include>")
    endif()
  endif()

  target_include_directories(
    ${targetname}
    INTERFACE ${public_includes}
              "$<INSTALL_INTERFACE:${CMAKE_INSTALL_FULL_INCLUDEDIR}>")

  target_include_directories(${targetname} SYSTEM
                             INTERFACE ${_SYSTEM_INCLUDE_DIRS})

  target_compile_definitions(${targetname}
                             INTERFACE ${_TRANSITIVE_COMPILE_DEFINITIONS})

  fcppt_utils_link_imported_targets(${targetname} INTERFACE
                                    ${_TRANSITIVE_IMPORTED_DEPS})

  if(NOT ${_VARIANT} STREQUAL INTERFACE)
    target_link_libraries(${targetname} PRIVATE ${_FCPPT_DEPS} ${_DEPS})
  endif()

  target_link_libraries(${targetname} INTERFACE ${_TRANSITIVE_DEPS}
                                                ${_TRANSITIVE_FCPPT_DEPS})

  fcppt_utils_export_install_target(${targetname})
endfunction()

# Add an fcppt library.
#
# lib_name: The name of the library.
# cur_files: The files that are part of this library.
# FCPPT_DEPS: A list of fcppt dependencies. The names are the same as used for
#             lib_name.
# TRANSITIVE_FCPPT_DEPS: A list of fcppt dependencies that are included by
#                        everything that uses this library in its FCPPT_DEPS.
# DEPS: A list of extra link targets.
# TRANSITIVE_DEPS: A list of extra link targets that are included by.
#                  everything that uses this library in its FCPPT_DEPS.
# INCLUDE_DIRS: A list of extra include directories.
# SYSTEM_INCLUDE_DIRS: A list of extra include directories included as
#                      -isystem.
# COMPILE_DEFINITIONS: A list of compile definitions.
# TRANSITIVE_COMPILE_DEFINITIONS: A list of compile definitions that are
#                                 included by everything that uses this
#                                 library in its FCPPT_DEPS.
# HEADER_ONLY_EXCEPTIONS: A list of headers to exclude from linting.
function(make_fcppt_library lib_name cur_files)
  set(option_args IS_INTERFACE HAS_IMPL_DIR)

  set(single_args SYMBOL_NAME)

  set(multi_args
      FCPPT_DEPS
      TRANSITIVE_FCPPT_DEPS
      DEPS
      TRANSITIVE_DEPS
      IMPORTED_DEPS
      TRANSITIVE_IMPORTED_DEPS
      INCLUDE_DIRS
      SYSTEM_INCLUDE_DIRS
      COMPILE_DEFINITIONS
      TRANSITIVE_COMPILE_DEFINITIONS
      HEADER_ONLY_EXCEPTIONS)

  set(full_name fcppt_${lib_name})

  cmake_parse_arguments("" "${option_args}" "${single_args}" "${multi_args}"
                        ${ARGN})

  string(TOUPPER ${lib_name} lib_name_UPPER)

  if("${_SYMBOL_NAME}" STREQUAL "")
    set(symbol_name FCPPT_${lib_name_UPPER})
  else()
    set(symbol_name ${_SYMBOL_NAME})
  endif()

  if(NOT ${_IS_INTERFACE})
    fcppt_generate_symbol_header(
      EXPORTS_NAME "${full_name}" SYMBOL_NAME "${symbol_name}_DETAIL"
      STATIC_LINK_FLAG "${FCPPT_STATIC_LINK_FLAG}")
  endif()

  fcppt_utils_interface_link_name(${full_name} INTERFACE_NAME)

  make_fcppt_library_base("${INTERFACE_NAME}" "" VARIANT "INTERFACE" ${ARGN})

  if((ENABLE_SHARED AND NOT ${_IS_INTERFACE}) OR ${FCPPT_UTILS_BUILD_HEADERS})
    make_fcppt_library_base("${full_name}" "${cur_files}" VARIANT "SHARED"
                            ${ARGN})
  endif()

  if(ENABLE_STATIC AND NOT ${_IS_INTERFACE})
    foreach(fcpptdep ${_FCPPT_DEPS})
      fcppt_utils_static_link_name(${fcpptdep} STATIC_NAME)

      list(APPEND REAL_FCPPT_DEPS ${STATIC_NAME})
    endforeach()

    fcppt_utils_static_link_name(${full_name} STATIC_NAME)

    make_fcppt_library_base(
      "${STATIC_NAME}"
      "${cur_files}"
      VARIANT
      "STATIC"
      FCPPT_DEPS
      ${REAL_FCPPT_DEPS}
      TRANSITIVE_FCPPT_DEPS
      ${_TRANSITIVE_FCPPT_DEPS}
      DEPS
      ${_DEPS}
      TRANSITIVE_DEPS
      ${_TRANSITIVE_DEPS}
      IMPORTED_DEPS
      ${_IMPORTED_DEPS}
      TRANSITIVE_IMPORTED_DEPS
      ${_TRANSITIVE_IMPORTED_DEPS}
      INCLUDE_DIRS
      ${_INCLUDE_DIRS}
      SYSTEM_INCLUDE_DIRS
      ${_SYSTEM_INCLUDE_DIRS}
      COMPILE_DEFINITIONS
      ${_COMPILE_DEFINITIONS}
      TRANSITIVE_COMPILE_DEFINITIONS
      ${_TRANSITIVE_COMPILE_DEFINITIONS})
  endif()

  install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endfunction()

if(CMAKE_COMPILER_IS_GNUCXX)
  set(IGNORE_NULL_DEREF "-Wno-null-dereference")
endif()

add_subdirectory(libs)

if(ENABLE_EXAMPLES)
  add_subdirectory(examples)
endif()

option(ENABLE_DOC "Build the documentation" OFF)

if(ENABLE_DOC)
  add_subdirectory(doc)
endif()

if(ENABLE_TEST)
  if(NOT ENABLE_CATCH)
    message(FATAL_ERROR "ENABLE_CATCH must be on if ENABLE_TEST is")
  endif()

  fcppt_utils_setup_tests()

  enable_testing()

  add_subdirectory(test)
endif()

fcppt_utils_generate_config(
  CONFIG_PATH ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake MODULES_PATH
  ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake/modules)

install(DIRECTORY ${FCPPT_UTILS_PROJECT_BINARY_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

set(FCPPT_CMAKE_MODULES_DIR ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake/modules)

install(
  FILES ${FCPPT_CMAKE_MODULES_DIR}/FcpptCMakeUtils.cmake
        ${FCPPT_CMAKE_MODULES_DIR}/FcpptCMakeUtilsPaths.cmake
        ${FCPPT_CMAKE_MODULES_DIR}/FcpptCMakeUtilsSettings.cmake
        ${FCPPT_CMAKE_MODULES_DIR}/FcpptCMakeUtilsClangTidy.cmake
        ${FCPPT_CMAKE_MODULES_DIR}/FcpptCMakeUtilsFunctions.cmake
        ${FCPPT_CMAKE_MODULES_DIR}/FcpptExport.cmake
        ${FCPPT_CMAKE_MODULES_DIR}/FcpptSymbol.cmake
  DESTINATION ${FCPPT_UTILS_INSTALL_CMAKEMODULES_DIR})
