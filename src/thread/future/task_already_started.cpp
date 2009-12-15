#include <fcppt/thread/future/task_already_started.hpp>
#include <fcppt/text.hpp>

fcppt::thread::future::task_already_started::task_already_started()
:
	exception(
		FCPPT_TEXT("task already started"))
{
}
