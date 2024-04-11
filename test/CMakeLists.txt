include(CMakeParseArguments)

# Add an fcppt test.
#
# path_name: The name of the cpp file without the extension.
#            For example path_name=array will refer to array.cpp.
# NO_CODE: Optional argument. If set, the test will not be run.
#          This is useful for tests that contain static_asserts only.
# COMPILE_OPTIONS: A list of extra compile options.
# INCLUDE_DIRS: A list of extra include directories.
# LINK_LIBS: A list of extra link targets.
function(add_fcppt_test path_name)
  set(option_args NO_CODE)

  set(multi_args COMPILE_OPTIONS INCLUDE_DIRS LINK_LIBS)

  cmake_parse_arguments("" "${option_args}" "" "${multi_args}" ${ARGN})

  if(_NO_CODE)
    set(no_code NO_CODE)
  else()
    list(APPEND _LINK_LIBS fcppt_catch_interface)
  endif()

  set(test_dir ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/test)

  fcppt_utils_add_test(
    ${test_dir}
    "${path_name}"
    ${no_code}
    LINK_LIBS
    ${_LINK_LIBS}
    fcppt_core_interface
    INCLUDE_DIRS
    ${_INCLUDE_DIRS}
    COMPILE_OPTIONS
    ${_COMPILE_OPTIONS})
endfunction()

fcppt_utils_link_target(fcppt_core)

fcppt_utils_link_target(fcppt_filesystem)

fcppt_utils_link_target(fcppt_log)

fcppt_utils_link_target(fcppt_options)

if(ENABLE_BOOST)
  set(FCPPT_TEST_BOOST_INTERFACE fcppt_boost_interface)
endif()

add_fcppt_test(absurd NO_CODE)

add_subdirectory(algorithm)

add_subdirectory(array)

add_fcppt_test(bit)

if(ENABLE_BOOST)
  add_fcppt_test(boost_units_value LINK_LIBS fcppt_boost_interface)
endif()

add_subdirectory(cast)

if(ENABLE_CATCH)
  add_subdirectory(catch)
endif()

add_fcppt_test(char_literal)

add_fcppt_test(cond)

add_fcppt_test(const)

add_subdirectory(concepts)

add_subdirectory(container)

add_fcppt_test(copy)

add_fcppt_test(cyclic_iterator)

add_fcppt_test(deref)

add_subdirectory(either)

add_fcppt_test(endianness LINK_LIBS "${fcppt_core_TARGET}")

add_subdirectory(enum)

add_fcppt_test(extract_from_string LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_test(extract_from_string_fmt LINK_LIBS "${fcppt_core_TARGET}")

add_subdirectory(filesystem)

add_fcppt_test(function)

add_fcppt_test(insert_to_string LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_test(int_range)

add_subdirectory(io)

add_subdirectory(iterator)

add_subdirectory(intrusive)

add_fcppt_test(is_reference NO_CODE)

add_fcppt_test(is_unique_ptr NO_CODE)

add_fcppt_test(literal)

if(ENABLE_BOOST)
  add_fcppt_test(literal_boost_units LINK_LIBS ${FCPPT_TEST_BOOST_INTERFACE})
endif()

add_fcppt_test(make_function)

add_fcppt_test(make_unique_ptr)

add_subdirectory(math)

add_subdirectory(monad)

add_subdirectory(mpl)

add_fcppt_test(move_clear)

add_fcppt_test(move_if_rvalue)

add_fcppt_test(move_if_rvalue_type NO_CODE)

add_fcppt_test(narrow LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_test(nonmovable NO_CODE)

add_fcppt_test(not NO_CODE)

add_subdirectory(optional)

add_subdirectory(options)

add_fcppt_test(output LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_test(overload)

add_subdirectory(parse)

add_subdirectory(random)

add_subdirectory(range)

add_subdirectory(record)

add_fcppt_test(recursive)

add_fcppt_test(reference)

add_fcppt_test(reference_to_base)

add_fcppt_test(reference_to_const)

add_fcppt_test(runtime_index)

if(ENABLE_BOOST)
  add_fcppt_test(scoped_state_machine LINK_LIBS fcppt_boost_interface)
endif()

add_subdirectory(shared_ptr)

add_subdirectory(signal)

add_fcppt_test(string_literal)

add_subdirectory(strong_typedef)

add_subdirectory(tuple)

add_subdirectory(type_traits)

add_fcppt_test(unique_ptr)

add_fcppt_test(unique_ptr_dynamic_cast)

add_fcppt_test(unique_ptr_from_std)

add_fcppt_test(unit)

add_fcppt_test(widen LINK_LIBS "${fcppt_core_TARGET}")

add_subdirectory(variant)
