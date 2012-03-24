set(
	FCPPT_THREAD_FILES
	include/fcppt/thread/hardware_concurrency.hpp
	include/fcppt/thread/hardware_concurrency_type.hpp
	include/fcppt/thread/id.hpp
	include/fcppt/thread/join_duration.hpp
	include/fcppt/thread/native_handle.hpp
	include/fcppt/thread/object.hpp
	include/fcppt/thread/sleep.hpp
	include/fcppt/thread/sleep_duration.hpp
	include/fcppt/thread/task.hpp
	include/fcppt/thread/yield.hpp
	src/thread/hardware_concurrency.cpp
	src/thread/include/fcppt/src/thread/to_boost_duration.hpp
	src/thread/object.cpp
	src/thread/sleep.cpp
	src/thread/yield.cpp
)

add_definitions(
	"${FcpptThreads_DEFINITIONS}"
)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

generate_symbol_header(
	"fcppt_thread"
	"FCPPT_THREAD"
)

make_fcppt_library(
	fcppt_thread
	"${FCPPT_THREAD_FILES}"
	""
	"${Boost_THREAD_LIBRARY};${FcpptThreads_LIBRARIES}"
	""
)
