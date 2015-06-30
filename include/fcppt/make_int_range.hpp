//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_INT_RANGE_HPP_INCLUDED
#define FCPPT_MAKE_INT_RANGE_HPP_INCLUDED

#include <fcppt/int_range_impl.hpp>


namespace fcppt
{

/**
\brief Creates a forward integer range

Creates the forward integer range [\a _begin, \a _end).

\ingroup fcpptvarious

\param _begin The first element in the range

\param _end One past the last element of the range
*/
template<
	typename Int
>
inline
fcppt::int_range<
	Int
>
make_int_range(
	Int const _begin,
	Int const _end
)
{
	return
		fcppt::int_range<
			Int
		>(
			_begin,
			_end
		);
}

}

#endif
