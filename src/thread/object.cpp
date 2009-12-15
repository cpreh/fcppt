#include <fcppt/thread/object.hpp>

fcppt::thread::object::object(
	task const &_task)
:
	thread_(
		_task)
{
}

void fcppt::thread::object::join()
{
	thread_.join();
}

fcppt::thread::object::~object()
{
	if (thread_.joinable())
		std::terminate();
}
