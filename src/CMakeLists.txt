FILE (
	GLOB_RECURSE fcpptfiles 
	*.cpp
)

FILE (
	GLOB_RECURSE fcpptheaders
	../include/*.hpp
)

SET (fcpptfiles ${fcpptfiles} ${fcpptheaders})

ADD_LIBRARY (fcppt SHARED ${fcpptfiles})

IF (NOT MSVC)
	TARGET_LINK_LIBRARIES (
		fcppt
		${Boost_LIBRARIES}
	)
ENDIF ()

INSTALL (TARGETS fcppt DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
