//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_FOR_EACH_HPP_INCLUDED
#define FCPPT_MPL_FOR_EACH_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/mpl/for_each_break.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Invoke a function on each element of a sequence without constructing them

\ingroup fcpptmpl

Invokes \a _function on each element of \a Sequence without constructing the
elements. This function is similar to <code>boost::mpl::for_each</code> but can
be used with unconstructible types like abstract classes. Calls
<code>_function(fcppt::tag<T>)</code> for each type T in \a Sequence.

\tparam Sequence The MPL sequence

\tparam Function The polymorphic function callable as <code>void
(fcppt::tag<T>)</code> for every T in \a Sequence.
*/
template<
	typename Sequence,
	typename Function
>
inline
void
for_each(
	Function const &_function
)
{
	fcppt::mpl::for_each_break<
		Sequence
	>(
		[
			&_function
		](
			auto const _element
		)
		{
			_function(
				_element
			);

			return
				fcppt::loop::continue_;
		}
	);
}

}
}

#endif
