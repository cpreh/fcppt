#include <fcppt/thread/future/uninitialized.hpp>
#include <fcppt/text.hpp>

fcppt::thread::future::uninitialized::uninitialized()
:
	exception(
		FCPPT_TEXT("uninitialized"))
{
}
