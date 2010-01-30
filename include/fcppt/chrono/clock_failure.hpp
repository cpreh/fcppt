//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_CLOCK_FAILURE_HPP_INCLUDED
#define FCPPT_CHRONO_CLOCK_FAILURE_HPP_INCLUDED

#include <fcppt/chrono/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace chrono
{

class FCPPT_CLASS_SYMBOL clock_failure
:
	public exception
{
public:
	FCPPT_SYMBOL explicit clock_failure(
		fcppt::string const &
	);
};

}
}

#endif
