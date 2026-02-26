include(CMakeParseArguments)

option(
  FCPPT_UTILS_BUILD_HEADERS
  "Build header files as well. This is useful for running misc-include-cleaner on your build."
  FALSE)

# Marks all header files from a list of files as files to compile.
# This is mainly useful so they can be compiled via clang-tidy and misc-include-cleaner.
#
# all_files: The list of files.
# HEADER_ONLY_EXCEPTIONS: Headers to be excluded from this process, e.g. if they are C headers.
function(fcppt_utils_add_headers all_files)
  set(multi_args HEADER_ONLY_EXCEPTIONS)

  cmake_parse_arguments("" "" "" "${multi_args}" ${ARGN})

  foreach(exclude_file ${_HEADER_ONLY_EXCEPTIONS})
    list(REMOVE_ITEM all_files ${exclude_file})
  endforeach()

  foreach(cur_file ${all_files})
    get_filename_component(CUR_EXT "${cur_file}" EXT)

    unset(cur_language)

    if("${CUR_EXT}" STREQUAL ".hpp")
      set(cur_language "CXX")
    elseif("${CUR_EXT}" STREQUAL ".h")
      set(cur_language "C")
    endif()

    if(DEFINED cur_language)
      set_source_files_properties(
        "${cur_file}" PROPERTIES LANGUAGE ${cur_language} HEADER_FILE_ONLY OFF)
    endif()
  endforeach()
endfunction()

# Adds source groups for a list of files.
function(fcppt_utils_add_source_groups all_files)
  foreach(cur_file ${all_files})
    get_filename_component(REL_PATH "${cur_file}" PATH)

    string(REPLACE "/" "\\" GROUPFOLDER "${REL_PATH}")

    source_group(${GROUPFOLDER} FILES ${cur_file})
  endforeach()

  if(FCPPT_UTILS_BUILD_HEADERS)
    fcppt_utils_add_headers("${all_files}")
  endif()
endfunction()

# Appends ${FCPPT_UTILS_PROJECT_SOURCE_DIR} to a list of files.
#
# files: The list of files.
# result: The resulting variable name.
function(fcppt_utils_append_source_dir files result)
  foreach(cur_file ${files})
    set(whole_file ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${cur_file})

    list(APPEND ${result} ${whole_file})
  endforeach()

  set(${result}
      ${${result}}
      PARENT_SCOPE)
endfunction()

# Appends ${FCPPT_UTILS_PROJECT_SOURCE_DIR} to a list of files
# and also adds source groups for them.
#
# files: The list of files.
# result: The resulting variable name.
function(fcppt_utils_append_source_dir_and_make_groups files result)
  set(multi_args HEADER_ONLY_EXCEPTIONS)

  cmake_parse_arguments("" "" "" "${multi_args}" ${ARGN})

  foreach(cur_file ${files})
    set(whole_file ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${cur_file})

    get_filename_component(REL_PATH ${cur_file} DIRECTORY)

    string(REPLACE "/" "\\" GROUPFOLDER "${REL_PATH}")

    source_group(${GROUPFOLDER} FILES ${whole_file})

    list(APPEND temp_result ${whole_file})
  endforeach()

  set(${result}
      "${temp_result}"
      PARENT_SCOPE)

  if(FCPPT_UTILS_BUILD_HEADERS)
    set(header_only_exceptions_abs)

    foreach(cur_file ${_HEADER_ONLY_EXCEPTIONS})
      set(whole_file ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${cur_file})

      list(APPEND header_only_exceptions_abs ${whole_file})
    endforeach()

    fcppt_utils_add_headers("${temp_result}" HEADER_ONLY_EXCEPTIONS
                            ${header_only_exceptions_abs})
  endif()
endfunction()

set(FCPPT_UTILS_EXPORT_NAME "${PROJECT_NAME}Export")

# Installs an exported target
# and also puts it in the ${FCPPT_UTILS_EXPORT_NAME} file.
#
# target_name: The name of the target.
function(fcppt_utils_export_install_target target_name)
  install(
    TARGETS ${target_name}
    DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    EXPORT "${FCPPT_UTILS_EXPORT_NAME}")
endfunction()

# Generates a config file for other projects to use via find_package.
# CONFIG_PATH: The path where the ${PROJECT_NAME}-config.cmake.in is.
# MODULES_PATH: Optional. A path that is appended to CMAKE_MODULE_PATH.
function(fcppt_utils_generate_config)
  set(single_args CONFIG_PATH MODULES_PATH)

  cmake_parse_arguments("" "" "${single_args}" "" ${ARGN})

  if(NOT "${_UNPARSED_ARGUMENTS}" STREQUAL "")
    message(FATAL_ERROR "Invalid parameters ${_UNPARSED_ARGUMENTS}")
  endif()

  if("${_CONFIG_PATH}" STREQUAL "")
    message(FATAL_ERROR "Missing CONFIG_PATH argument.")
  endif()

  set(config_name "${PROJECT_NAME}-config.cmake")

  set(config_in_file "${_CONFIG_PATH}/${config_name}.in")

  set(build_config_dir "${FCPPT_UTILS_PROJECT_BINARY_DIR}/config")

  set(targets_file_name "${PROJECT_NAME}Targets.cmake")

  # Build config
  set(ADDITIONAL_MODULE_PATH ${_MODULES_PATH})

  configure_file(${config_in_file} "${build_config_dir}/${config_name}" @ONLY)

  export(EXPORT "${FCPPT_UTILS_EXPORT_NAME}"
         FILE "${build_config_dir}/${targets_file_name}")

  # Install config
  set(ADDITIONAL_MODULE_PATH ${FCPPT_UTILS_INSTALL_FULL_CMAKEMODULES_DIR})

  set(config_dest_install "${build_config_dir}_install/${config_name}")

  configure_file(${config_in_file} ${config_dest_install} @ONLY)

  install(FILES "${config_dest_install}"
          DESTINATION "${FCPPT_UTILS_INSTALL_CMAKECONFIG_DIR}")

  install(
    EXPORT "${FCPPT_UTILS_EXPORT_NAME}"
    FILE "${targets_file_name}"
    DESTINATION "${FCPPT_UTILS_INSTALL_CMAKECONFIG_DIR}")
endfunction()

# Handles overriding .so versions.
#
# cache_var: The name of the cache variable to store the overriden .so version.
# out_var: The name of the output variable.
# default_version: The .so version to use if the cache var is empty.
function(fcppt_utils_handle_so_version cache_var out_var default_version)
  set("${cache_var}"
      ""
      CACHE STRING
            "The custom .so version to use. If empty, the default will be used."
  )

  if("${${cache_var}}" STREQUAL "")
    set("${out_var}"
        "${default_version}"
        PARENT_SCOPE)
  else()
    set("${out_var}"
        "${${cache_var}}"
        PARENT_SCOPE)
  endif()
endfunction()

# Adds a dummy target, which is useful for header only libraries.
#
# target_name: The name of the target.
# target_files: The files of the target.
# INCLUDE_DIRS: Additional include directories.
function(fcppt_utils_add_dummy_target target_name target_files)
  set(multi_args INCLUDE_DIRS LINK_LIBS)

  cmake_parse_arguments("" "" "" "${multi_args}" ${ARGN})

  if(NOT "${_UNPARSED_ARGUMENTS}" STREQUAL "")
    message(FATAL_ERROR "Invalid parameters ${_UNPARSED_ARGUMENTS}")
  endif()

  set(libname "${target_name}_dummy")

  add_library("${libname}" STATIC ${target_files})

  set_target_properties("${libname}" PROPERTIES LINKER_LANGUAGE "CXX")

  target_include_directories(${libname} PRIVATE ${_INCLUDE_DIRS})

  target_link_libraries(${libname} PRIVATE ${_LINK_LIBS})
endfunction()

# Sets fcppt's target options.
#
# target_name: The name of the target.
# IS_C: If this is a C (not C++) target.
# ADDITIONAL_FLAGS: Additional compile flags to use.
function(fcppt_utils_set_target_compiler_flags target_name)
  set(option_args IS_C)
  set(multi_args ADDITIONAL_FLAGS)

  cmake_parse_arguments("" "${option_args}" "" "${multi_args}" ${ARGN})

  if(${_IS_C})
    if(MSVC)
      list(APPEND _ADDITIONAL_FLAGS /std:clatest)
    endif()

    target_compile_options(${target_name} PRIVATE ${_ADDITIONAL_FLAGS})
  else()
    target_compile_options(${target_name} PRIVATE ${FCPPT_UTILS_COMPILE_OPTIONS}
                                                  ${_ADDITIONAL_FLAGS})
  endif()

  set_target_properties(
    ${target_name}
    PROPERTIES CXX_EXTENSIONS FALSE
               CXX_STANDARD 23
               CXX_STANDARD_REQUIRED 23
               C_EXTENSIONS FALSE
               C_STANDARD 23
               C_STANDARD_REQUIRED 23
               NO_SYSTEM_FROM_IMPORTED TRUE)

  get_target_property(TARGET_TYPE ${target_name} TYPE)

  if(${TARGET_TYPE} STREQUAL "SHARED_LIBRARY")
    target_link_libraries(${target_name}
                          PRIVATE ${FCPPT_UTILS_SHARED_LINKER_FLAGS})
  endif()

  if(${TARGET_TYPE} STREQUAL "EXECUTABLE")
    target_link_libraries(${target_name}
                          PRIVATE ${FCPPT_UTILS_EXE_LINKER_FLAGS})
  endif()
endfunction()

# Adds ENABLE_SHARED and ENABLE_STATIC options.
function(fcppt_utils_static_shared)
  option(ENABLE_SHARED "Build shared libraries" ON)

  option(ENABLE_STATIC "Build static libraries" OFF)

  if(NOT ENABLE_SHARED AND NOT ENABLE_STATIC)
    message(FATAL_ERROR "You disabled both STATIC and SHARED")
  endif()

  if(ENABLE_STATIC)
    set(FCPPT_UTILS_DEFAULT_LINK_STATIC
        TRUE
        PARENT_SCOPE)
  endif()

  # shared overrides static
  if(ENABLE_SHARED)
    set(FCPPT_UTILS_DEFAULT_LINK_STATIC
        FALSE
        PARENT_SCOPE)
  endif()
endfunction()

# The name to use for static libraries.
#
# libname: The name of the (shared) library.
# result: The name of the result variable.
function(fcppt_utils_static_link_name libname result)
  set(${result}
      ${libname}_static
      PARENT_SCOPE)
endfunction()

# The name to use for interface libraries.
#
# libname: The name of the (shared) library.
# result: The name of the result variable.
function(fcppt_utils_interface_link_name libname result)
  set(${result}
      ${libname}_interface
      PARENT_SCOPE)
endfunction()

# Gets the name of a static or shared library to link to,
# depending on ENABLE_STATIC and ENABLE_SHARED.
#
# libname: The name of the (shared) library.
# Sets ${libname}_TARGET as output.
function(fcppt_utils_link_target libname)
  set(target_name ${libname}_TARGET)

  if(FCPPT_UTILS_DEFAULT_LINK_STATIC)
    fcppt_utils_static_link_name(${libname} STATIC_NAME)

    set(${target_name}
        ${STATIC_NAME}
        PARENT_SCOPE)
  else()
    set(${target_name}
        ${libname}
        PARENT_SCOPE)
  endif()
endfunction()

# Sets the flag ${link_flag} for ${target_name} if ${variant} is equal to "STATIC".
# This is useful in functions that handle
# the creation of static and shared libraries simultaneously.
#
# target_name: The name of the library.
# variant: If this is a static or shared library.
# link_flag: The static link flag to use.
function(fcppt_utils_interface_static_link target_name variant link_flag)
  if(${variant} STREQUAL "STATIC")
    target_compile_definitions(${target_name} PUBLIC ${link_flag})
  endif()
endfunction()

# Sets the target folder of a target.
#
# target_name: The name of the target.
# prefix: A prefix for the folder name to use.
# path_name: The path of the target.
function(fcppt_utils_set_target_folder target_name prefix path_name)
  string(FIND ${path_name} "/" LAST_PART REVERSE)

  if(NOT LAST_PART EQUAL -1)
    string(SUBSTRING ${path_name} 0 ${LAST_PART} folder_name)

    set(folder_name "/${folder_name}")
  endif()

  set_target_properties(
    ${target_name} PROPERTIES FOLDER ${PROJECT_NAME}/${prefix}${folder_name})
endfunction()

# Initializes the tests. Searches for Catch2.
function(fcppt_utils_setup_tests)
  find_package(Catch2 3.0 REQUIRED)
endfunction()

# Adds a test case.
#
# test_dir: The top-level directory for test cases.
# path_anme: The inner path of the test case, including the file name but without the .cpp extension.
#            For example, "foo/bar" will result in "foo/bar.cpp".
# LINK_LIBS: A list of extra link targets.
# INCLUDE_DIRS: A list of extra include directories.
# SYSTEM_INCLUDE_DIRS: A list of extra system include directories.
# COMPILE_DEFINITIONS: A list of compile definitions.
# COMPILE_OPTIONS: A list of extra compile options.
function(fcppt_utils_add_test test_dir path_name)
  set(option_args NO_CODE)

  set(multi_args LINK_LIBS INCLUDE_DIRS COMPILE_DEFINITIONS COMPILE_OPTIONS SYSTEM_INCLUDE_DIRS)

  cmake_parse_arguments("" "${option_args}" "" "${multi_args}" ${ARGN})

  string(REPLACE "/" "_" TEST_NAME ${path_name})

  set(full_test_name ${PROJECT_NAME}_test_${TEST_NAME})

  add_executable(${full_test_name} ${test_dir}/${path_name}.cpp)

  fcppt_utils_set_target_folder(${full_test_name} tests ${path_name})

  fcppt_utils_set_target_compiler_flags(${full_test_name})

  target_include_directories(${full_test_name} PRIVATE ${_INCLUDE_DIRS})

  target_include_directories(${full_test_name} SYSTEM PRIVATE ${_SYSTEM_INCLUDE_DIRS})

  target_compile_definitions(${full_test_name} PRIVATE ${_COMPILE_DEFINITIONS})

  target_compile_options(${full_test_name} PRIVATE ${_COMPILE_OPTIONS})

  target_link_libraries(${full_test_name} PRIVATE ${_LINK_LIBS})

  if(NOT ${_NO_CODE})
    target_link_libraries(${full_test_name} PRIVATE Catch2::Catch2WithMain)

    add_test(NAME ${TEST_NAME} COMMAND ${full_test_name})
  endif()

  if(FCPPT_UTILS_COMPILER_IS_CLANGPP)
    target_compile_options(${full_test_name} PRIVATE "-Wno-c2y-extensions")
  endif()
endfunction()

# Adds an example.
#
# test_dir: The top-level directory for test cases.
# path_anme: The inner path of the example, including the file name but without the .cpp extension.
#            For example, "foo/bar" will result in "foo/bar.cpp" if IS_C is not set.
# IS_C: If this is a C (not C++) test case.
# INSTALL_DIR: The directory to install this test into. If unset, the example will not be installed.
# LINK_LIBS: A list of extra link targets.
# INCLUDE_DIRS: A list of extra include directories.
# SYSTEM_INCLUDE_DIRS: A list of extra system include directories.
# COMPILE_DEFINITIONS: A list of compile definitions.
# COMPILE_OPTIONS: A list of extra compile options.
function(fcppt_utils_add_example example_dir path_name)
  set(option_args IS_C)

  set(single_args INSTALL_DIR)

  set(multi_args LINK_LIBS INCLUDE_DIRS COMPILE_DEFINITIONS COMPILE_OPTIONS SYSTEM_INCLUDE_DIRS)

  cmake_parse_arguments("" "${option_args}" "${single_args}" "${multi_args}"
                        ${ARGN})

  string(REPLACE "/" "_" EXAMPLE_NAME ${path_name})

  set(full_example_name ${PROJECT_NAME}_example_${EXAMPLE_NAME})

  if(${_IS_C})
    set(suffix "c")

    set(is_c IS_C)
  else()
    set(suffix "cpp")
  endif()

  add_executable(${full_example_name} ${example_dir}/${path_name}.${suffix})

  fcppt_utils_set_target_folder(${full_example_name} examples ${path_name})

  target_compile_definitions(${full_example_name}
                             PRIVATE ${_COMPILE_DEFINITIONS})

  target_compile_options(${full_example_name} PRIVATE ${_COMPILE_OPTIONS})

  target_include_directories(${full_example_name} PRIVATE ${_INCLUDE_DIRS})

  target_include_directories(${full_example_name} SYSTEM PRIVATE ${_SYSTEM_INCLUDE_DIRS})

  fcppt_utils_set_target_compiler_flags(${full_example_name} ${is_c})

  target_link_libraries(${full_example_name} PRIVATE ${_LINK_LIBS})

  if(NOT "${_INSTALL_DIR}" STREQUAL "")
    install(TARGETS ${full_example_name} DESTINATION "${_INSTALL_DIR}")
  endif()
endfunction()

# Uses an imported target indirectly.
#
# This is basically the same as
#
# target_link_libraries(${target_name} ${visibility} ${imported_name})
#
# but without mentioning ${imported_name} directly. thus CMake does
# not see that the imported target is actually in use.
#
# target_name: The name of the target to modify.
# visibility: PUBLIC, PRIVATE or INTERFACE
# imported_name: The name of the imported target.
function(fcppt_utils_link_imported_target_single target_name visibility
         imported_name)
  get_target_property(INCLUDE_DIRS ${imported_name}
                      INTERFACE_INCLUDE_DIRECTORIES)

  if(NOT "${INCLUDE_DIRS}" STREQUAL "INCLUDE_DIRS-NOTFOUND")
    target_include_directories(${target_name} ${visibility} ${INCLUDE_DIRS})
  endif()

  get_target_property(SYSTEM_INCLUDE_DIRS ${imported_name}
                      INTERFACE_SYSTEM_INCLUDE_DIRECTORIES)

  if(NOT "${SYSTEM_INCLUDE_DIRS}" STREQUAL "SYSTEM_INCLUDE_DIRS-NOTFOUND")
    target_include_directories(${target_name} SYSTEM ${visibility}
                               ${SYSTEM_INCLUDE_DIRS})
  endif()

  get_target_property(LINK_LIBRARIES ${imported_name} INTERFACE_LINK_LIBRARIES)

  if(NOT "${LINK_LIBRARIES}" STREQUAL "LINK_LIBRARIES-NOTFOUND")
    target_link_libraries(${target_name} ${visibility} ${LINK_LIBRARIES})
  endif()

  get_target_property(COMPILE_OPTIONS ${imported_name}
                      INTERFACE_COMPILE_OPTIONS)

  if(NOT "${COMPILE_OPTIONS}" STREQUAL "COMPILE_OPTIONS-NOTFOUND")
    target_compile_options(${target_name} ${visibility} ${COMPILE_OPTIONS})
  endif()

  get_target_property(COMPILE_DEFINITIONS ${imported_name}
                      INTERFACE_COMPILE_DEFINITIONS)

  if(NOT "${COMPILE_DEFINITIONS}" STREQUAL "COMPILE_DEFINITIONS-NOTFOUND")
    target_compile_definitions(${target_name} ${visibility}
                                              ${COMPILE_DEFINITIONS})
  endif()
endfunction()

# Uses multiple imported targets.
#
# This is basically the same as
#
# target_link_libraries(${target_name} ${visibility} ${ARGN})
#
# See fcppt_utils_link_imported_target_single.
#
# target_name: The name of the target to modify.
# visibility: PUBLIC, PRIVATE or INTERFACE
function(fcppt_utils_link_imported_targets target_name visibility)
  foreach(cur_name ${ARGN})
    fcppt_utils_link_imported_target_single(${target_name} ${visibility}
                                            ${cur_name})
  endforeach()
endfunction()

# Loads the contents of a text file into a variable, including the file name itself.

# sources: A file relative to the project's source dir.
# result: The name of the result variable.
function(fcppt_utils_load_source_files sources result)
  set(input_file ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${sources})
  set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${input_file})
  file(STRINGS ${input_file} temp_list)
  list(APPEND temp_list ${sources})
  set(${result} ${temp_list} PARENT_SCOPE)
endfunction()
