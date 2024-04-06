include(CMakeParseArguments)

function(fcppt_generate_symbol_header)
  set(SINGLE_ARGS STATIC_LINK_FLAG EXPORTS_NAME SYMBOL_NAME RELATIVE_PATH IS_C)

  cmake_parse_arguments("" "" "${SINGLE_ARGS}" "" ${ARGN})

  if("${_STATIC_LINK_FLAG}" STREQUAL "")
    set(_STATIC_LINK_FLAG "${SYMBOL_NAME}_STATIC_LINK")
  endif()

  if("${_EXPORTS_NAME}" STREQUAL "")
    message(FATAL_ERROR "EXPORTS_NAME must be specified")
  endif()

  if("${_SYMBOL_NAME}" STREQUAL "")
    message(FATAL_ERROR "SYMBOL_NAME must be specified")
  endif()

  if("${_RELATIVE_PATH}" STREQUAL "")
    string(TOLOWER ${_SYMBOL_NAME} SYMBOL_NAME_LOWER)

    string(REPLACE "_" "/" _RELATIVE_PATH ${SYMBOL_NAME_LOWER})
  endif()

  set(SYMBOL_NAME_LONG "${_SYMBOL_NAME}_SYMBOL")

  set(BINARY_DIR "${${PROJECT_NAME}_BINARY_DIR}")

  set(TEMP_FILE "${BINARY_DIR}/${SYMBOL_NAME_LONG}_generate_symbol.h.in")

  if(_IS_C)
    set(SUFFIX_LOWER "h")

    set(SUFFIX_UPPER "H")
  else()
    set(SUFFIX_LOWER "hpp")

    set(SUFFIX_UPPER "HPP")
  endif()

  file(
    WRITE "${TEMP_FILE}"
    "
#ifndef ${SYMBOL_NAME_LONG}_${SUFFIX_UPPER}_INCLUDED
#define ${SYMBOL_NAME_LONG}_${SUFFIX_UPPER}_INCLUDED

#if defined(${_STATIC_LINK_FLAG})
#	define ${SYMBOL_NAME_LONG}
#elif defined(${_EXPORTS_NAME}_EXPORTS)
#	include <fcppt/symbol/export.${SUFFIX_LOWER}>
#	define ${SYMBOL_NAME_LONG} FCPPT_SYMBOL_EXPORT
#else
#	include <fcppt/symbol/import.${SUFFIX_LOWER}>
#	define ${SYMBOL_NAME_LONG} FCPPT_SYMBOL_IMPORT
#endif

#endif
")

  configure_file(
    "${TEMP_FILE}"
    "${BINARY_DIR}/include/${_RELATIVE_PATH}/symbol.${SUFFIX_LOWER}" COPYONLY)
endfunction()
