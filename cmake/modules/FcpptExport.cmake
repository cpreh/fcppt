set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

# Include the generated export file.
# Has to be called at the beginning of a config file.
# project_export_name: The name of the exported project.
function(fcppt_export_init project_export_name)
  if(NOT FCPPT_DONT_EXPORT)
    get_filename_component(FCPPT_EXPORT_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

    include("${FCPPT_EXPORT_DIR}/${project_export_name}Targets.cmake")
  endif()
endfunction()

# Generates the exported targets.
# Has to be called in a config file.
# If use_static_libs is ON then static targets will be imported.
function(fcppt_export_generate_targets use_static_libs)
  foreach(target ${ARGN})
    set(target_name "${target}_TARGET")

    if(use_static_libs)
      set("${target_name}"
          "${target}_static"
          PARENT_SCOPE)
    else()
      set("${target_name}"
          "${target}"
          PARENT_SCOPE)
    endif()
  endforeach()
endfunction()
