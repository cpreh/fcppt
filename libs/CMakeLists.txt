if(ENABLE_BOOST)
  add_subdirectory(boost)
endif()

if(ENABLE_CATCH)
  add_subdirectory(catch)
endif()

add_subdirectory(core)

add_subdirectory(filesystem)

add_subdirectory(log)

add_subdirectory(options)

add_subdirectory(parse)
