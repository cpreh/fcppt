#include <fcppt/thread/future/already_retrieved.hpp>
#include <fcppt/text.hpp>

fcppt::thread::future::already_retrieved::already_retrieved()
:
	exception(
		FCPPT_TEXT("already retrieved"))
{
}
