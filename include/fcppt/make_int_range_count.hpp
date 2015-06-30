//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_INT_RANGE_COUNT_HPP_INCLUDED
#define FCPPT_MAKE_INT_RANGE_COUNT_HPP_INCLUDED

#include <fcppt/int_range_impl.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/make_int_range.hpp>


namespace fcppt
{

/**
\brief Creates a forward integer range starting at zero

Creates the forward integer range [0, \a _count). The purpose of this class is
to create integer ranges over integer-like types (not just fundamental
integers), for example strong typedefs of integers.

\ingroup fcpptvarious

\param _count The number of elements in the range
*/
template<
	typename Int
>
inline
fcppt::int_range<
	Int
>
make_int_range_count(
	Int const _count
)
{
	return
		fcppt::make_int_range(
			fcppt::literal<
				Int
			>(
				0
			),
			_count
		);
}

}

#endif
