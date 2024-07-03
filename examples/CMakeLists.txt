fcppt_utils_link_target(fcppt_core)

fcppt_utils_link_target(fcppt_filesystem)

fcppt_utils_link_target(fcppt_log)

fcppt_utils_link_target(fcppt_options)

# Add an fcppt example.
#
# path_name: The name of the cpp file without the extension.
#            For example path_name=array will refer to array.cpp.
# IS_C: Optional argument. If set, the test will be a C test (not C++).
# COMPILE_DEFINITIONS: A list of compile definitions.
# LINK_LIBS: A list of extra link targets.
# INCLUDE_DIRS: A list of extra include directories.
function(add_fcppt_example path_name)
  set(option_args IS_C)

  set(multi_args LINK_LIBS COMPILE_DEFINITIONS INCLUDE_DIRS SYSTEM_INCLUDE_DIRS)

  cmake_parse_arguments("" "${option_args}" "" "${multi_args}" ${ARGN})

  if(_IS_C)
    set(is_c IS_C)
  endif()

  list(APPEND _INCLUDE_DIRS ${FCPPT_UTILS_PROJECT_BINARY_DIR}/include)

  fcppt_utils_add_example(
    ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/examples
    ${path_name}
    ${is_c}
    LINK_LIBS
    ${_LINK_LIBS}
    COMPILE_DEFINITIONS
    ${_COMPILE_DEFINITIONS}
    INCLUDE_DIRS
    ${_INCLUDE_DIRS}
    SYSTEM_INCLUDE_DIRS
    ${_SYSTEM_INCLUDE_DIRS})
endfunction()

add_fcppt_example(algorithm LINK_LIBS fcppt_core_interface)

add_fcppt_example(array LINK_LIBS fcppt_core_interface)

add_fcppt_example(assert_complete LINK_LIBS fcppt_core_interface)

add_fcppt_example(assign LINK_LIBS fcppt_core_interface)

add_fcppt_example(cast LINK_LIBS fcppt_core_interface)

add_fcppt_example(config LINK_LIBS fcppt_core_interface)

add_fcppt_example(coding_style LINK_LIBS fcppt_core_interface)

add_fcppt_example(cyclic_iterator LINK_LIBS fcppt_core_interface)

add_fcppt_example(endianness LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_example(enum LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_example(either LINK_LIBS fcppt_core_interface)

add_fcppt_example(iterator LINK_LIBS fcppt_core_interface)

add_fcppt_example(intrusive LINK_LIBS fcppt_core_interface)

add_fcppt_example(literal LINK_LIBS fcppt_core_interface)

add_fcppt_example(main LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_example(no_cpp IS_C LINK_LIBS fcppt_core_interface)

add_fcppt_example(noncopyable LINK_LIBS fcppt_core_interface)

add_fcppt_example(nonmovable LINK_LIBS fcppt_core_interface)

add_fcppt_example(optional LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_example(output_tm LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_example(record LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_example(smart_ptr_deleter LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_example(shared_ptr LINK_LIBS fcppt_core_interface)

add_fcppt_example(string LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_example(string_conversion LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_example(strong_typedef LINK_LIBS fcppt_core_interface)

add_fcppt_example(type_iso LINK_LIBS fcppt_core_interface)

add_fcppt_example(unique_ptr LINK_LIBS fcppt_core_interface)

add_fcppt_example(version LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_example(visibility LINK_LIBS fcppt_core_interface)

add_fcppt_example(weak_ptr LINK_LIBS fcppt_core_interface)

add_subdirectory(cast)

add_subdirectory(container)

add_subdirectory(io)

add_subdirectory(log)

add_subdirectory(math)

add_subdirectory(mpl)

add_subdirectory(options)

add_subdirectory(parse)

add_subdirectory(preprocessor)

add_subdirectory(random)

add_subdirectory(signal)

add_subdirectory(variant)
