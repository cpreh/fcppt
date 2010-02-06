//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_THREAD_OBJECT_HPP_INCLUDED
#define FCPPT_THREAD_OBJECT_HPP_INCLUDED

#include <fcppt/thread/task.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <boost/thread/thread.hpp>

namespace fcppt
{
namespace thread
{

class object
{
	FCPPT_NONCOPYABLE(object)
public:
	FCPPT_SYMBOL object(
		thread::task const &
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
