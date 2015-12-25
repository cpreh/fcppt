//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MOVE_IF_HPP_INCLUDED
#define FCPPT_MOVE_IF_HPP_INCLUDED

#include <fcppt/detail/move_if.hpp>


namespace fcppt
{

/**
\brief Moves an object if a condition is true

\ingroup fcpptvarious

Moves \a _arg iff \a Cond is true.
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
	Arg &_arg
)
{
	return
		fcppt::detail::move_if<
			Cond
		> :: execute(
			_arg
		);
}

}

#endif
