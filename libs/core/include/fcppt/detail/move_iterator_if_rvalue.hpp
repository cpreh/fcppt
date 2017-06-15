//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_MOVE_ITERATOR_IF_RVALUE_HPP_INCLUDED
#define FCPPT_DETAIL_MOVE_ITERATOR_IF_RVALUE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Type,
	typename Iterator
>
inline
typename
boost::enable_if<
	std::is_lvalue_reference<
		Type
	>,
	Iterator
>::type
move_iterator_if_rvalue(
	Iterator const &_iterator
)
{
	return
		_iterator;
}

template<
	typename Type,
	typename Iterator
>
inline
typename
boost::disable_if<
	std::is_lvalue_reference<
		Type
	>,
	decltype(
		std::make_move_iterator(
			std::declval<
				Iterator const &
			>()
		)
	)
>::type
move_iterator_if_rvalue(
	Iterator const &_iterator
)
{
	return
		std::make_move_iterator(
			_iterator
		);
}

}
}

#endif
