//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_EXCLUSIVE_RANGE_ERROR_HPP_INCLUDED
#define FCPPT_RANDOM_EXCLUSIVE_RANGE_ERROR_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/class_symbol.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace random
{

/// Thrown if an exclusive_range is wrong
class FCPPT_CLASS_SYMBOL exclusive_range_error
:
	public exception
{
public:
	FCPPT_SYMBOL explicit exclusive_range_error(
		fcppt::string const &
	);
};

}
}

#endif
