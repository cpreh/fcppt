include(CMakeParseArguments)

option(
  FCPPT_UTILS_BUILD_HEADERS
  "Build header files as well. This is useful for running misc-include-cleaner on your build."
  FALSE)

function(fcppt_utils_add_headers ALL_FILES)
  set(MULTI_ARGS HEADER_ONLY_EXCEPTIONS)

  cmake_parse_arguments("" "" "" "${MULTI_ARGS}" ${ARGN})

  foreach(EXCLUDE_FILE ${_HEADER_ONLY_EXCEPTIONS})
    list(REMOVE_ITEM ALL_FILES ${EXCLUDE_FILE})
  endforeach()

  foreach(CUR_FILE ${ALL_FILES})
    get_filename_component(CUR_EXT "${CUR_FILE}" EXT)

    unset(CUR_LANGUAGE)

    if("${CUR_EXT}" STREQUAL ".hpp")
      set(CUR_LANGUAGE "CXX")
    elseif("${CUR_EXT}" STREQUAL ".h")
      set(CUR_LANGUAGE "C")
    endif()

    if(DEFINED CUR_LANGUAGE)
      set_source_files_properties(
        "${CUR_FILE}" PROPERTIES LANGUAGE ${CUR_LANGUAGE} HEADER_FILE_ONLY OFF)
    endif()
  endforeach()
endfunction()

function(fcppt_utils_add_source_groups ALL_FILES)
  foreach(CURFILE ${ALL_FILES})
    get_filename_component(REL_PATH "${CURFILE}" PATH)

    string(REPLACE "/" "\\" GROUPFOLDER "${REL_PATH}")

    source_group(${GROUPFOLDER} FILES ${CURFILE})
  endforeach()

  if(FCPPT_UTILS_BUILD_HEADERS)
    fcppt_utils_add_headers("${ALL_FILES}")
  endif()
endfunction()

function(fcppt_utils_append_source_dir FILES RESULT)
  foreach(CUR_FILE ${FILES})
    set(WHOLE_FILE ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${CUR_FILE})

    list(APPEND ${RESULT} ${WHOLE_FILE})
  endforeach()

  set(${RESULT}
      ${${RESULT}}
      PARENT_SCOPE)
endfunction()

function(fcppt_utils_append_source_dir_and_make_groups FILES RESULT)
  set(MULTI_ARGS HEADER_ONLY_EXCEPTIONS)

  cmake_parse_arguments("" "" "" "${MULTI_ARGS}" ${ARGN})

  foreach(CUR_FILE ${FILES})
    set(WHOLE_FILE ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${CUR_FILE})

    get_filename_component(REL_PATH ${CUR_FILE} DIRECTORY)

    string(REPLACE "/" "\\" GROUPFOLDER "${REL_PATH}")

    source_group(${GROUPFOLDER} FILES ${WHOLE_FILE})

    list(APPEND TEMP_RESULT ${WHOLE_FILE})
  endforeach()

  set(${RESULT}
      "${TEMP_RESULT}"
      PARENT_SCOPE)

  if(FCPPT_UTILS_BUILD_HEADERS)
    set(HEADER_ONLY_EXCEPTIONS_ABS)

    foreach(CUR_FILE ${_HEADER_ONLY_EXCEPTIONS})
      set(WHOLE_FILE ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${CUR_FILE})

      list(APPEND HEADER_ONLY_EXCEPTIONS_ABS ${WHOLE_FILE})
    endforeach()

    fcppt_utils_add_headers("${TEMP_RESULT}" HEADER_ONLY_EXCEPTIONS
                            ${HEADER_ONLY_EXCEPTIONS_ABS})
  endif()
endfunction()

set(FCPPT_UTILS_EXPORT_NAME "${PROJECT_NAME}Export")

function(fcppt_utils_export_install_target TARGETNAME)
  install(
    TARGETS ${TARGETNAME}
    DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    EXPORT "${FCPPT_UTILS_EXPORT_NAME}")
endfunction()

# CONFIG_PATH : PATH - The path where the ${PROJECT_NAME}-config.cmake.in
# resides. [MODULES_PATH : PATH] - The path that is appended to
# CMAKE_MODULE_PATH.
function(fcppt_utils_generate_config)
  set(SINGLE_ARGS CONFIG_PATH MODULES_PATH)

  cmake_parse_arguments("" "" "${SINGLE_ARGS}" "" ${ARGN})

  if(NOT "${_UNPARSED_ARGUMENTS}" STREQUAL "")
    message(FATAL_ERROR "Invalid parameters ${_UNPARSED_ARGUMENTS}")
  endif()

  if("${_CONFIG_PATH}" STREQUAL "")
    message(FATAL_ERROR "Missing CONFIG_PATH argument.")
  endif()

  set(CONFIG_NAME "${PROJECT_NAME}-config.cmake")

  set(CONFIG_IN_FILE "${_CONFIG_PATH}/${CONFIG_NAME}.in")

  set(BUILD_CONFIG_DIR "${FCPPT_UTILS_PROJECT_BINARY_DIR}/config")

  set(TARGETS_FILE_NAME "${PROJECT_NAME}Targets.cmake")

  # Build config
  set(ADDITIONAL_MODULE_PATH ${_MODULES_PATH})

  configure_file(${CONFIG_IN_FILE} "${BUILD_CONFIG_DIR}/${CONFIG_NAME}" @ONLY)

  export(EXPORT "${FCPPT_UTILS_EXPORT_NAME}"
         FILE "${BUILD_CONFIG_DIR}/${TARGETS_FILE_NAME}")

  # Install config
  set(ADDITIONAL_MODULE_PATH ${FCPPT_UTILS_INSTALL_FULL_CMAKEMODULES_DIR})

  set(CONFIG_DEST_INSTALL "${BUILD_CONFIG_DIR}_install/${CONFIG_NAME}")

  configure_file(${CONFIG_IN_FILE} ${CONFIG_DEST_INSTALL} @ONLY)

  install(FILES "${CONFIG_DEST_INSTALL}"
          DESTINATION "${FCPPT_UTILS_INSTALL_CMAKECONFIG_DIR}")

  install(
    EXPORT "${FCPPT_UTILS_EXPORT_NAME}"
    FILE "${TARGETS_FILE_NAME}"
    DESTINATION "${FCPPT_UTILS_INSTALL_CMAKECONFIG_DIR}")
endfunction()

function(fcppt_utils_handle_so_version CACHE_VAR OUT_VAR DEFAULT_VERSION)
  set("${CACHE_VAR}"
      ""
      CACHE STRING
            "The custom .so version to use. If empty, the default will be used."
  )

  if("${${CACHE_VAR}}" STREQUAL "")
    set("${OUT_VAR}"
        "${DEFAULT_VERSION}"
        PARENT_SCOPE)
  else()
    set("${OUT_VAR}"
        "${${CACHE_VAR}}"
        PARENT_SCOPE)
  endif()
endfunction()

function(fcppt_utils_add_dummy_target TARGET_NAME TARGET_FILES)
  set(MULTI_ARGS INCLUDE_DIRS LINK_LIBS)

  cmake_parse_arguments("" "" "" "${MULTI_ARGS}" ${ARGN})

  if(NOT "${_UNPARSED_ARGUMENTS}" STREQUAL "")
    message(FATAL_ERROR "Invalid parameters ${_UNPARSED_ARGUMENTS}")
  endif()

  set(LIBNAME "${TARGET_NAME}_dummy")

  add_library("${LIBNAME}" STATIC ${TARGET_FILES})

  set_target_properties("${LIBNAME}" PROPERTIES LINKER_LANGUAGE "CXX")

  target_include_directories(${LIBNAME} PRIVATE ${_INCLUDE_DIRS})

  target_link_libraries(${LIBNAME} PRIVATE ${_LINK_LIBS})
endfunction()

function(fcppt_utils_set_target_compiler_flags TARGET_NAME)
  set(MULTI_ARGS ADDITIONAL_FLAGS)

  cmake_parse_arguments("" "" "" "${MULTI_ARGS}" ${ARGN})

  target_compile_options(${TARGET_NAME} PRIVATE ${FCPPT_UTILS_COMPILE_OPTIONS}
                                                ${_ADDITIONAL_FLAGS})

  set_target_properties(
    ${TARGET_NAME}
    PROPERTIES CXX_EXTENSIONS FALSE
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED 20
               NO_SYSTEM_FROM_IMPORTED TRUE)

  get_target_property(TARGET_TYPE ${TARGET_NAME} TYPE)

  if(${TARGET_TYPE} STREQUAL "SHARED_LIBRARY")
    target_link_libraries(${TARGET_NAME}
                          PRIVATE ${FCPPT_UTILS_SHARED_LINKER_FLAGS})
  endif()

  if(${TARGET_TYPE} STREQUAL "EXECUTABLE")
    target_link_libraries(${TARGET_NAME}
                          PRIVATE ${FCPPT_UTILS_EXE_LINKER_FLAGS})
  endif()
endfunction()

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

function(fcppt_utils_static_link_name LIBNAME RESULT)
  set(${RESULT}
      ${LIBNAME}_static
      PARENT_SCOPE)
endfunction()

function(fcppt_utils_interface_link_name LIBNAME RESULT)
  set(${RESULT}
      ${LIBNAME}_interface
      PARENT_SCOPE)
endfunction()

function(fcppt_utils_link_target LIBNAME)
  set(TARGET_NAME ${LIBNAME}_TARGET)

  if(FCPPT_UTILS_DEFAULT_LINK_STATIC)
    fcppt_utils_static_link_name(${LIBNAME} STATIC_NAME)

    set(${TARGET_NAME}
        ${STATIC_NAME}
        PARENT_SCOPE)
  else()
    set(${TARGET_NAME}
        ${LIBNAME}
        PARENT_SCOPE)
  endif()
endfunction()

function(fcppt_utils_interface_static_link TARGET_NAME VARIANT LINK_FLAG)
  if(${VARIANT} STREQUAL "STATIC")
    target_compile_definitions(${TARGET_NAME} PUBLIC ${LINK_FLAG})
  endif()
endfunction()

function(fcppt_utils_set_target_folder TARGET_NAME PREFIX PATH_NAME)
  string(FIND ${PATH_NAME} "/" LAST_PART REVERSE)

  if(NOT LAST_PART EQUAL -1)
    string(SUBSTRING ${PATH_NAME} 0 ${LAST_PART} FOLDER_NAME)

    set(FOLDER_NAME "/${FOLDER_NAME}")
  endif()

  set_target_properties(
    ${TARGET_NAME} PROPERTIES FOLDER ${PROJECT_NAME}/${PREFIX}${FOLDER_NAME})
endfunction()

function(fcppt_utils_setup_tests)
  find_package(Catch2 3.0 REQUIRED)
endfunction()

function(fcppt_utils_add_test TEST_DIR PATH_NAME)
  set(OPTION_ARGS NO_CODE)

  set(MULTI_ARGS LINK_LIBS INCLUDE_DIRS COMPILE_DEFINITIONS COMPILE_OPTIONS)

  cmake_parse_arguments("" "${OPTION_ARGS}" "" "${MULTI_ARGS}" ${ARGN})

  string(REPLACE "/" "_" TEST_NAME ${PATH_NAME})

  set(FULL_TEST_NAME ${PROJECT_NAME}_test_${TEST_NAME})

  add_executable(${FULL_TEST_NAME} ${TEST_DIR}/${PATH_NAME}.cpp)

  fcppt_utils_set_target_folder(${FULL_TEST_NAME} tests ${PATH_NAME})

  fcppt_utils_set_target_compiler_flags(${FULL_TEST_NAME})

  target_include_directories(${FULL_TEST_NAME} PRIVATE ${_INCLUDE_DIRS})

  target_compile_definitions(${FULL_TEST_NAME} PRIVATE ${_COMPILE_DEFINITIONS})

  target_compile_options(${FULL_TEST_NAME} PRIVATE ${_COMPILE_OPTIONS})

  target_link_libraries(${FULL_TEST_NAME} PRIVATE ${_LINK_LIBS})

  if(NOT ${_NO_CODE})
    target_link_libraries(${FULL_TEST_NAME} PRIVATE Catch2::Catch2WithMain)

    add_test(NAME ${TEST_NAME} COMMAND ${FULL_TEST_NAME})
  endif()
endfunction()

function(fcppt_utils_add_example EXAMPLE_DIR PATH_NAME)
  set(OPTION_ARGS IS_C)

  set(SINGLE_ARGS INSTALL_DIR)

  set(MULTI_ARGS LINK_LIBS INCLUDE_DIRS COMPILE_DEFINITIONS COMPILE_OPTIONS)

  cmake_parse_arguments("" "${OPTION_ARGS}" "${SINGLE_ARGS}" "${MULTI_ARGS}"
                        ${ARGN})

  string(REPLACE "/" "_" EXAMPLE_NAME ${PATH_NAME})

  set(FULL_EXAMPLE_NAME ${PROJECT_NAME}_example_${EXAMPLE_NAME})

  if(${_IS_C})
    set(SUFFIX "c")
  else()
    set(SUFFIX "cpp")
  endif()

  add_executable(${FULL_EXAMPLE_NAME} ${EXAMPLE_DIR}/${PATH_NAME}.${SUFFIX})

  fcppt_utils_set_target_folder(${FULL_EXAMPLE_NAME} examples ${PATH_NAME})

  target_compile_definitions(${FULL_EXAMPLE_NAME}
                             PRIVATE ${_COMPILE_DEFINITIONS})

  target_compile_options(${FULL_EXAMPLE_NAME} PRIVATE ${_COMPILE_OPTIONS})

  target_include_directories(${FULL_EXAMPLE_NAME} PRIVATE ${_INCLUDE_DIRS})

  if(NOT _IS_C)
    fcppt_utils_set_target_compiler_flags(${FULL_EXAMPLE_NAME})
  endif()

  target_link_libraries(${FULL_EXAMPLE_NAME} PRIVATE ${_LINK_LIBS})

  if(NOT "${_INSTALL_DIR}" STREQUAL "")
    install(TARGETS ${FULL_EXAMPLE_NAME} DESTINATION "${_INSTALL_DIR}")
  endif()
endfunction()

function(fcppt_utils_link_imported_target_single TARGET_NAME VISIBILITY
         IMPORTED_NAME)
  get_target_property(INCLUDE_DIRS ${IMPORTED_NAME}
                      INTERFACE_INCLUDE_DIRECTORIES)

  if(NOT "${INCLUDE_DIRS}" STREQUAL "INCLUDE_DIRS-NOTFOUND")
    target_include_directories(${TARGET_NAME} ${VISIBILITY} ${INCLUDE_DIRS})
  endif()

  get_target_property(SYSTEM_INCLUDE_DIRS ${IMPORTED_NAME}
                      INTERFACE_SYSTEM_INCLUDE_DIRECTORIES)

  if(NOT "${SYSTEM_INCLUDE_DIRS}" STREQUAL "SYSTEM_INCLUDE_DIRS-NOTFOUND")
    target_include_directories(${TARGET_NAME} SYSTEM ${VISIBILITY}
                               ${SYSTEM_INCLUDE_DIRS})
  endif()

  get_target_property(LINK_LIBRARIES ${IMPORTED_NAME} INTERFACE_LINK_LIBRARIES)

  if(NOT "${LINK_LIBRARIES}" STREQUAL "LINK_LIBRARIES-NOTFOUND")
    target_link_libraries(${TARGET_NAME} ${VISIBILITY} ${LINK_LIBRARIES})
  endif()

  get_target_property(COMPILE_OPTIONS ${IMPORTED_NAME}
                      INTERFACE_COMPILE_OPTIONS)

  if(NOT "${COMPILE_OPTIONS}" STREQUAL "COMPILE_OPTIONS-NOTFOUND")
    target_compile_options(${TARGET_NAME} ${VISIBILITY} ${COMPILE_OPTIONS})
  endif()

  get_target_property(COMPILE_DEFINITIONS ${IMPORTED_NAME}
                      INTERFACE_COMPILE_DEFINITIONS)

  if(NOT "${COMPILE_DEFINITIONS}" STREQUAL "COMPILE_DEFINITIONS-NOTFOUND")
    target_compile_definitions(${TARGET_NAME} ${VISIBILITY}
                                              ${COMPILE_DEFINITIONS})
  endif()
endfunction()

function(fcppt_utils_link_imported_targets TARGET_NAME VISIBILITY)
  foreach(CURNAME ${ARGN})
    fcppt_utils_link_imported_target_single(${TARGET_NAME} ${VISIBILITY}
                                            ${CURNAME})
  endforeach()
endfunction()
