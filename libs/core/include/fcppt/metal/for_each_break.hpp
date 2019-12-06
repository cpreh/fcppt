//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_FOR_EACH_BREAK_HPP_INCLUDED
#define FCPPT_METAL_FOR_EACH_BREAK_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/metal/detail/for_each_break.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{

/**
\brief Invoke a function on each element of a sequence
while giving the ability to break out of the loop.

\ingroup fcpptmetal

\tparam Sequence Must be a metal::list.

\tparam Function A polymorphic function callable as <code>fcppt::loop
(fcppt::tag<T>)</code> for every T in \a Sequence.
*/
template<
	typename Sequence,
	typename Function
>
inline
void
for_each_break(
	Function const &_function
)
{
	return
		fcppt::metal::detail::for_each_break<
			Sequence,
			fcppt::literal<
				::metal::int_
			>(
				0
			)
		>(
			_function
		);
}

}
}

#endif
