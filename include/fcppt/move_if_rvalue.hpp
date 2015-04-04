//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MOVE_IF_RVALUE_HPP_INCLUDED
#define FCPPT_MOVE_IF_RVALUE_HPP_INCLUDED

#include <fcppt/detail/move_if_rvalue.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Moves an object if a type is an rvalue

\ingroup fcpptvarious

Moves \a _arg iff \a Type is an rvalue.
*/
template<
	typename Type,
	typename Arg
>
inline
decltype(
	fcppt::detail::move_if_rvalue<
		Type
	>(
		std::declval<
			Arg &
		>()
	)
)
move_if_rvalue(
	Arg &_arg
)
{
	return
		fcppt::detail::move_if_rvalue<
			Type
		>(
			_arg
		);
}

}

#endif
