if(
	NOT
	${PROJECT_NAME}
	STREQUAL
	"fcppt"
	AND
	NOT
	fcppt_FOUND
)
	message(
		FATAL_ERROR
		"FcpptCMakeUtils included without prior find_package(fcppt)"
	)
endif()

include(
	FcpptCMakeUtilsPaths
)

include(
	FcpptCMakeUtilsSettings
)

include(
	FcpptCMakeUtilsClangTidy
)

include(
	FcpptCMakeUtilsFunctions
)
