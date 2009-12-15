#include <fcppt/thread/future/moved.hpp>
#include <fcppt/text.hpp>

fcppt::thread::future::moved::moved()
:
	exception(
		FCPPT_TEXT("moved"))
{
}
