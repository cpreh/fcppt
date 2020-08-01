//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_LOCATION_EQUAL_HPP_INCLUDED
#define FCPPT_PARSE_LOCATION_EQUAL_HPP_INCLUDED

#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/parse/location_impl.hpp>


namespace fcppt
{
namespace parse
{

inline
bool
operator==(
	fcppt::parse::location const &_left,
	fcppt::parse::location const &_right
)
{
	return
		_left.line() == _right.line()
		&&
		_left.column() == _right.column();
}

}
}

#endif
