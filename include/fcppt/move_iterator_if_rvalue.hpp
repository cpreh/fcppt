//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MOVE_ITERATOR_IF_RVALUE_HPP_INCLUDED
#define FCPPT_MOVE_ITERATOR_IF_RVALUE_HPP_INCLUDED

#include <fcppt/detail/move_iterator_if_rvalue.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Makes a move iterator if a type is an rvalue

\ingroup fcpptvarious

Makes a move iterator out of \a _iterator iff \a Type is an rvalue.
*/
template<
	typename Type,
	typename Iterator
>
inline
decltype(
	fcppt::detail::move_iterator_if_rvalue<
		Type
	>(
		std::declval<
			Iterator const &
		>()
	)
)
move_iterator_if_rvalue(
	Iterator const &_iterator
)
{
	return
		fcppt::detail::move_iterator_if_rvalue<
			Type
		>(
			_iterator
		);
}

}

#endif
