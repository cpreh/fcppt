//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_INT_RANGE_HPP_INCLUDED
#define FCPPT_MAKE_INT_RANGE_HPP_INCLUDED

#include <fcppt/literal.hpp>


namespace fcppt
{

template<
	typename Int
>
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
