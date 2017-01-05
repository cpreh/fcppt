if(
	ENABLE_FILESYSTEM
)
	add_subdirectory(
		filesystem
	)
endif()

add_subdirectory(
	core
)

add_subdirectory(
	log
)

add_subdirectory(
	options
)
