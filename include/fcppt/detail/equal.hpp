//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_EQUAL_HPP_INCLUDED
#define FCPPT_DETAIL_EQUAL_HPP_INCLUDED

#include <fcppt/detail/equal_functor.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Iterator1,
	typename Iterator2
>
bool
equal(
	Iterator1 const _beg1,
	Iterator1 const _end1,
	Iterator2 const _beg2
)
{
	return
		std::equal(
			_beg1,
			_end1,
			_beg2,
			fcppt::detail::equal_functor()
		);
}

}
}

#endif
