//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MOVE_IF_HPP_INCLUDED
#define FCPPT_MOVE_IF_HPP_INCLUDED

#include <fcppt/detail/move_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Moves an object if a condition is true

\ingroup fcpptvarious

Moves \a _arg if \a Cond is true or \a Arg is an rvalue.
*/
template<
	bool Cond,
	typename Arg
>
inline
decltype(
	auto
)
move_if(
	Arg &&_arg
)
{
	return
		fcppt::detail::move_if<
			Cond
			||
			!std::is_lvalue_reference<
				Arg
			>::value
		> :: execute(
			_arg
		);
}

}

#endif
