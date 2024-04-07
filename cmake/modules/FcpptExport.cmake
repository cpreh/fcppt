set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

function(fcppt_export_init PROJECT_NAME)
  if(NOT FCPPT_DONT_EXPORT)
    get_filename_component(FCPPT_EXPORT_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

    include("${FCPPT_EXPORT_DIR}/${PROJECT_NAME}Targets.cmake")
  endif()
endfunction()

function(fcppt_export_generate_targets USE_STATIC_LIBS)
  foreach(TARGET ${ARGN})
    set(TARGET_NAME "${TARGET}_TARGET")

    if(USE_STATIC_LIBS)
      set("${TARGET_NAME}"
          "${TARGET}_static"
          PARENT_SCOPE)
    else()
      set("${TARGET_NAME}"
          "${TARGET}"
          PARENT_SCOPE)
    endif()
  endforeach()
endfunction()
