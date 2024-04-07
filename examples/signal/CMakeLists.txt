# Create a signal example.
function(add_fcppt_signal_example example_name)
  add_fcppt_example(signal/${example_name} ${ARGN})
endfunction()

if(${SIGNALS_BENCHMARK_BACKEND} STREQUAL "boostsignals2")
  add_fcppt_signal_example(
    benchmark
    LINK_LIBS
    fcppt_core_interface
    INCLUDE_DIRS
    ${Boost_INCLUDE_DIRS}
    COMPILE_DEFINITIONS
    FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_BOOST_SIGNALS2)
else()
  add_fcppt_signal_example(
    benchmark LINK_LIBS fcppt_core_interface COMPILE_DEFINITIONS
    FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_FCPPT)
endif()

add_fcppt_signal_example(combine LINK_LIBS fcppt_core_interface)

add_fcppt_signal_example(connection LINK_LIBS fcppt_core_interface)

add_fcppt_signal_example(simple LINK_LIBS fcppt_core_interface)

add_fcppt_signal_example(unregister LINK_LIBS fcppt_core_interface)
