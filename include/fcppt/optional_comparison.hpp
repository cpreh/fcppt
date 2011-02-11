//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_COMPARISON_HPP_INCLUDED
#define FCPPT_OPTIONAL_COMPARISON_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>

namespace fcppt
{

template<
	typename T
>
bool
operator==(
	optional<T> const &_a,
	optional<T> const &_b
)
{
	return
		_a && _b
		?
			*_a == *_b
		:
			_a.has_value() == _b.has_value();
}

template<
	typename T
>
bool
operator!=(
	optional<T> const &_a,
	optional<T> const &_b
)
{
	return
		!(_a == _b);
}

}

#endif
