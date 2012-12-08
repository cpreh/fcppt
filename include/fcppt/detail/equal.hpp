//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_EQUAL_HPP_INCLUDED
#define FCPPT_DETAIL_EQUAL_HPP_INCLUDED

#include <fcppt/detail/equal_functor.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <algorithm>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Iterator
>
typename boost::enable_if<
	std::is_floating_point<
		typename std::iterator_traits<
			Iterator
		>::value_type
	>,
	bool
>::type
equal(
	Iterator const _beg1,
	Iterator const _end1,
	Iterator const _beg2
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

template<
	typename Iterator
>
typename boost::disable_if<
	std::is_floating_point<
		typename std::iterator_traits<
			Iterator
		>::value_type
	>,
	bool
>::type
equal(
	Iterator const _beg1,
	Iterator const _end1,
	Iterator const _beg2
)
{
	return
		std::equal(
			_beg1,
			_end1,
			_beg2
		);
}

}
}

#endif
