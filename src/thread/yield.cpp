//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/thread/yield.hpp>
#include <boost/thread/thread.hpp>

void
fcppt::thread::yield()
{
	return boost::thread::yield();
}
