find_path(
	BRIGAND_INCLUDE_DIR
	brigand/brigand.hpp
	HINTS
	"${BRIGAND_INCLUDEDIR}"
)

include(
	FindPackageHandleStandardArgs
)

find_package_handle_standard_args(
	BRIGAND
	DEFAULT_MSG
	BRIGAND_INCLUDE_DIR
)

if(
	BRIGAND_FOUND
)
	set(
		BRIGAND_INCLUDE_DIRS
		"${BRIGAND_INCLUDE_DIR}"
	)
endif()

mark_as_advanced(
	BRIGAND_INCLUDE_DIR
)
