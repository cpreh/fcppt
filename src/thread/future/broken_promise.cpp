#include <fcppt/thread/future/broken_promise.hpp>
#include <fcppt/text.hpp>

fcppt::thread::future::broken_promise::broken_promise()
:
	exception(
		FCPPT_TEXT("broken promise"))
{
}
