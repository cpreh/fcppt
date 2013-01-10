add_definitions(
	${FCPPT_CONFIG_LINK_MACROS}
)

function(
	make_fcppt_example
	SUBNAME
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINES
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

	set_target_properties(
		${FCPPT_EXAMPLE_NAME}
		PROPERTIES
		COMPILE_FLAGS
		"${ADDITIONAL_DEFINES}"
	)

	fcppt_link_target(
		fcppt_core
	)

	target_link_libraries(
		${FCPPT_EXAMPLE_NAME}
		${fcppt_core_TARGET}
		${FCPPT_DEFAULT_LINK_TARGET}
		${ADDITIONAL_DEPS}
	)
endfunction()

function(
	add_fcppt_example
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINES
)
	make_fcppt_example(
		""
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		"${ADDITIONAL_DEFINES}"
	)
endfunction()

add_fcppt_example(algorithm "" "")
add_fcppt_example(assert "" "")
add_fcppt_example(assert_complete "" "")
add_fcppt_example(backtrace "${Boost_CHRONO_LIBRARIES};${Boost_SYSTEM_LIBRARY}" "")
add_fcppt_example(chrono_asio "${FcpptThreads_LIBRARIES};${Boost_CHRONO_LIBRARIES};${Boost_SYSTEM_LIBRARY}" "${FcpptThreads_DEFINITIONS}")
add_fcppt_example(codecvt "" "")
add_fcppt_example(container "" "")
add_fcppt_example(cyclic_iterator "" "")
add_fcppt_example(dynamic_cast "" "")
add_fcppt_example(endianness "" "")
add_fcppt_example(foreach_enumerator "" "")
add_fcppt_example(homogenous_pair "" "")
add_fcppt_example(io "" "")
add_fcppt_example(log "" "")
add_fcppt_example(make_container "" "")
add_fcppt_example(math "" "")
add_fcppt_example(noncopyable "" "")
add_fcppt_example(optional "" "")
add_fcppt_example(optional_dynamic_cast "" "")
add_fcppt_example(output_tm "" "")
add_fcppt_example(random "${Boost_CHRONO_LIBRARIES};${Boost_SYSTEM_LIBRARY}" "")
add_fcppt_example(safe_numeric_cast "" "")
add_fcppt_example(scoped_ptr "" "")
add_fcppt_example(shared_ptr "" "")
add_fcppt_example(sleep "" "")
add_fcppt_example(string_conversion "" "")
add_fcppt_example(strongtypedef "" "")
add_fcppt_example(time_parse "" "")
add_fcppt_example(truncation_check_cast "" "")
add_fcppt_example(type_traits "" "")
add_fcppt_example(unique_ptr "" "")
add_fcppt_example(version "" "")
add_fcppt_example(visibility "" "")
add_fcppt_example(weak_ptr "" "")

add_subdirectory(container)
add_subdirectory(doc)
add_subdirectory(log)
add_subdirectory(math)
add_subdirectory(mpl)
add_subdirectory(preprocessor)
add_subdirectory(signal)
add_subdirectory(variant)
