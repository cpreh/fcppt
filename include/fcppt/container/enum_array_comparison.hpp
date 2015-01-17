//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ENUM_ARRAY_COMPARISON_HPP_INCLUDED
#define FCPPT_CONTAINER_ENUM_ARRAY_COMPARISON_HPP_INCLUDED

#include <fcppt/container/enum_array_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

template<
	typename Enum,
	typename Value
>
bool
operator==(
	fcppt::container::enum_array<
		Enum,
		Value
	> const &_a,
	fcppt::container::enum_array<
		Enum,
		Value
	> const &_b
)
{
	return
		std::equal(
			_a.begin(),
			_a.end(),
			_b.begin()
		);
}

template<
	typename Enum,
	typename Value
>
inline
bool
operator!=(
	fcppt::container::enum_array<
		Enum,
		Value
	> const &_a,
	fcppt::container::enum_array<
		Enum,
		Value
	> const &_b
)
{
	return
		!(_a == _b);
}

}
}

#endif
