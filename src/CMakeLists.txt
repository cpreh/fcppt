FILE (
	GLOB_RECURSE fccptfiles 
	*.cpp
)

FILE (
	GLOB_RECURSE fccptheaders
	../include/*.hpp
)

SET (fccptfiles ${fccptfiles} ${fccptheaders})

ADD_LIBRARY (fccpt SHARED ${fccptfiles})

IF (NOT MSVC)
	TARGET_LINK_LIBRARIES (
		fccpt
		${Boost_LIBRARIES}
	)
ENDIF ()

INSTALL (TARGETS fccpt DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
