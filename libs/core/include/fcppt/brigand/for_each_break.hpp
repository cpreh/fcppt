//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_FOR_EACH_BREAK_HPP_INCLUDED
#define FCPPT_BRIGAND_FOR_EACH_BREAK_HPP_INCLUDED

#include <fcppt/brigand/detail/for_each_break.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Invoke a function on each element of a sequence without constructing
them and giving the ability to break out of the loop

\ingroup fcpptbrigand

Similar to fcppt::brigand::for_each, but can break out of a loop early.

\see fcppt::brigand::for_each

\tparam Function The polymorphic function callable as <code>fcppt::loop
(fcppt::tag<T>)</code> for every T in \a Sequence.
*/
template<
	typename List,
	typename Function
>
inline
void
for_each_break(
	Function const &_function
)
{
	return
		fcppt::brigand::detail::for_each_break<
			List,
			0u
		>(
			_function
		);
}

}
}

#endif
