include(CMakeParseArguments)

# Generates a symbol header.
# STATIC_LINK_FLAG: The -D flag to determine if static linking is used.
#                   Defaults to ${SYMBOL_NAME}_STATIC_LINK.
# EXPORTS_NAME: The exports name set by cmake. If set to mylib, then
#               mylib_EXPORTS is used.
# SYMBOL_NAME: The name to use for the export definitions symbol.
#              If set to mylib, then mylib_SYMBOL is used.
# RELATIVE_PATH: The path to use after include/.
#                Defaults to ${SYMBOL_NAME} in lower case
#                and _ replaced with /.
# IS_C: Whether the file for C (not C++).
function(fcppt_generate_symbol_header)
  set(single_args STATIC_LINK_FLAG EXPORTS_NAME SYMBOL_NAME RELATIVE_PATH IS_C)

  cmake_parse_arguments("" "" "${single_args}" "" ${ARGN})

  if("${_STATIC_LINK_FLAG}" STREQUAL "")
    set(static_link_flag "${SYMBOL_NAME}_STATIC_LINK")
  else()
    set(static_link_flag ${_STATIC_LINK_FLAG})
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

  set(symbol_name_long "${_SYMBOL_NAME}_SYMBOL")

  set(binary_dir "${${PROJECT_NAME}_BINARY_DIR}")

  set(temp_file "${binary_dir}/${symbol_name_long}_generate_symbol.h.in")

  if(_IS_C)
    set(suffix_lower "h")

    set(suffix_upper "H")
  else()
    set(suffix_lower "hpp")

    set(suffix_upper "HPP")
  endif()

  file(
    WRITE "${temp_file}"
    "
#ifndef ${symbol_name_long}_${suffix_upper}_INCLUDED
#define ${symbol_name_long}_${suffix_upper}_INCLUDED

#ifdef ${static_link_flag}
#	define ${symbol_name_long}
#elifdef ${_EXPORTS_NAME}_EXPORTS
#	include <fcppt/symbol/export.${suffix_lower}>
#	define ${symbol_name_long} FCPPT_SYMBOL_EXPORT
#else
#	include <fcppt/symbol/import.${suffix_lower}>
#	define ${symbol_name_long} FCPPT_SYMBOL_IMPORT
#endif

#endif
")

  configure_file(
    "${temp_file}"
    "${binary_dir}/include/${_RELATIVE_PATH}/symbol.${suffix_lower}" COPYONLY)
endfunction()
