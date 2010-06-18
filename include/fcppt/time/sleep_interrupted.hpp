//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_SLEEP_INTERRUPTED_HPP_INCLUDED
#define FCPPT_TIME_SLEEP_INTERRUPTED_HPP_INCLUDED

#include <fcppt/time/exception.hpp>

namespace fcppt
{
namespace time
{

/// May be thrown if a sleep gets interrupted
class sleep_interrupted
:
	public time::exception
{
public:
	sleep_interrupted();
};

}
}

#include <fcppt/time/impl/sleep_interrupted.hpp>

#endif
