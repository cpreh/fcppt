//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_CLOCK_FAILURE_HPP_INCLUDED
#define FCPPT_CHRONO_CLOCK_FAILURE_HPP_INCLUDED

#include <fcppt/chrono/exception.hpp>
#include <fcppt/string.hpp>

namespace fcppt
{
namespace chrono
{

/// May be thrown by a clock's now() function
class clock_failure
:
	public exception
{
public:
	explicit clock_failure(
		fcppt::string const &
	);
};

}
}

#include <fcppt/chrono/impl/clock_failure.hpp>

#endif
