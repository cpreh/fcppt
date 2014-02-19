set(
	CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS
	ON
)

function(
	fcppt_export_init
	PROJECT_NAME
)
	get_filename_component(
		FCPPT_EXPORT_DIR
		"${CMAKE_CURRENT_LIST_FILE}"
		PATH
	)

	include(
		"${FCPPT_EXPORT_DIR}/${PROJECT_NAME}Targets.cmake"
	)
endfunction()

function(
	fcppt_export_generate_targets
	TARGETS
	USE_STATIC_LIBS
)
	set(
		FCPPT_EXPORT_USE_STATIC_LIBS
		${USE_STATIC_LIBS}
	)

	foreach(
		TARGET
		${TARGETS}
	)
		set(
			TARGET_NAME
			"${TARGET}_TARGET"
		)

		if(
			FCPPT_EXPORT_USE_STATIC_LIBS
		)
			set(
				"${TARGET_NAME}"
				"${TARGET}_static"
				PARENT_SCOPE
			)
		else()
			set(
				"${TARGET_NAME}"
				"${TARGET}"
				PARENT_SCOPE
			)
		endif()
	endforeach()
endfunction()
