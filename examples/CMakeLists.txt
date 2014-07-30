add_definitions(
	${FCPPT_CONFIG_LINK_MACROS}
)

fcppt_link_target(
	fcppt_core
)

function(
	make_fcppt_example
	SUBNAME
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINITIONS
)
	if(
		"${SUBNAME}"
		STREQUAL
		""
	)
		set(
			FCPPT_EXAMPLE_NAME
			example_${MAINNAME}
		)
	else()
		set(
			FCPPT_EXAMPLE_NAME
			example_${SUBNAME}_${MAINNAME}
		)
	endif()

	add_executable(
		${FCPPT_EXAMPLE_NAME}
		${MAINNAME}.cpp
	)

	target_compile_definitions(
		${FCPPT_EXAMPLE_NAME}
		PRIVATE
		"${ADDITIONAL_DEFINITIONS}"
	)

	fcppt_utils_set_target_compiler_flags(
		${FCPPT_EXAMPLE_NAME}
	)

	target_link_libraries(
		${FCPPT_EXAMPLE_NAME}
		"${ADDITIONAL_DEPS}"
	)
endfunction()

function(
	add_fcppt_example
	MAINNAME
	ADDITIONAL_DEPS
)
	make_fcppt_example(
		""
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		""
	)
endfunction()

add_fcppt_example(algorithm "")
add_fcppt_example(assert "${fcppt_core_TARGET}")
add_fcppt_example(assert_complete "")
add_fcppt_example(backtrace "${fcppt_core_TARGET};${Boost_SYSTEM_LIBRARY}")
add_fcppt_example(casts "")
add_fcppt_example(codecvt "${fcppt_core_TARGET}")
add_fcppt_example(container "${fcppt_core_TARGET}")
add_fcppt_example(cyclic_iterator "")
add_fcppt_example(dynamic_cast "${fcppt_core_TARGET}")
add_fcppt_example(endianness "${fcppt_core_TARGET}")
add_fcppt_example(enum "")
add_fcppt_example(homogenous_pair "${fcppt_core_TARGET}")
add_fcppt_example(log "${fcppt_core_TARGET}")
add_fcppt_example(make_container "")
add_fcppt_example(math "${fcppt_core_TARGET}")
add_fcppt_example(noncopyable "")
add_fcppt_example(optional "${fcppt_core_TARGET}")
add_fcppt_example(optional_dynamic_cast "")
add_fcppt_example(output_tm "${fcppt_core_TARGET}")
add_fcppt_example(safe_numeric_cast "")
add_fcppt_example(smart_ptr_deleter "${fcppt_core_TARGET}")
add_fcppt_example(shared_ptr "${fcppt_core_TARGET}")
add_fcppt_example(sleep "${fcppt_core_TARGET}")
add_fcppt_example(string_conversion "${fcppt_core_TARGET}")
add_fcppt_example(strongtypedef "${fcppt_core_TARGET}")
add_fcppt_example(time_parse "${fcppt_core_TARGET}")
add_fcppt_example(truncation_check_cast "${fcppt_core_TARGET}")
add_fcppt_example(type_traits "")
add_fcppt_example(unique_ptr "${fcppt_core_TARGET}")
add_fcppt_example(version "${fcppt_core_TARGET}")
add_fcppt_example(visibility "")
add_fcppt_example(weak_ptr "${fcppt_core_TARGET}")

add_subdirectory(container)
add_subdirectory(doc)
add_subdirectory(io)
add_subdirectory(log)
add_subdirectory(math)
add_subdirectory(mpl)
add_subdirectory(preprocessor)
add_subdirectory(random)
add_subdirectory(signal)
add_subdirectory(variant)
