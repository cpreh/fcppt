//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MOVE_IF_RVALUE_HPP_INCLUDED
#define FCPPT_MOVE_IF_RVALUE_HPP_INCLUDED

#include <fcppt/move_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Moves an object if a type is an rvalue

\ingroup fcpptvarious

Moves \a _arg if \a Type is an rvalue or if \a Arg is an rvalue. The behavior
is similar to <code>std::forward</code> except that this function depends on
two types instead of one. This can be useful in situations where you want to
move a member if the surrounding object is an rvalue.
*/
template<
	typename Type,
	typename Arg
>
inline
decltype(
	auto
)
move_if_rvalue(
	Arg &&_arg
)
{
	return
		fcppt::move_if<
			!std::is_lvalue_reference<
				Type
			>::value
		>(
			std::forward<
				Arg
			>(
				_arg
			)
		);
}

}

#endif
