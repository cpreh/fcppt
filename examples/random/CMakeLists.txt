# Create a random example.
function(add_fcppt_random_example example_name)
  add_fcppt_example(random/${example_name} ${ARGN})
endfunction()

if(ENABLE_BOOST)
  add_fcppt_random_example(complex LINK_LIBS fcppt_boost_interface fcppt_core_interface SYSTEM_INCLUDE_DIRS ${Boost_INCLUDE_DIRS})
endif()

add_fcppt_random_example(enum LINK_LIBS fcppt_core_interface)

add_fcppt_random_example(simple LINK_LIBS fcppt_core_interface)

add_fcppt_random_example(strong_typedef LINK_LIBS fcppt_core_interface)

add_fcppt_random_example(transform LINK_LIBS fcppt_core_interface)
