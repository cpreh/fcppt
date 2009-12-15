#include <fcppt/thread/sleep.hpp>
#include <boost/thread/thread.hpp>

void fcppt::thread::sleep(
	int const i)
{
	boost::this_thread::sleep(
		boost::posix_time::seconds(
			i));
}
