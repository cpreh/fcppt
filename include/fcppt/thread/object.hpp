#ifndef FCPPT_THREAD_OBJECT_HPP_INCLUDED
#define FCPPT_THREAD_OBJECT_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/function/object.hpp>
#include <boost/thread.hpp>

namespace fcppt
{
namespace thread
{
class FCPPT_CLASS_SYMBOL object
{
public:
	typedef fcppt::function::object<void ()> task;

	FCPPT_SYMBOL object(
		task const &
	);

	FCPPT_SYMBOL void
	join();

	FCPPT_SYMBOL ~object();
private:
	boost::thread thread_;
};
}
}

#endif // FCPPT_THREAD_OBJECT_HPP_INCLUDED
