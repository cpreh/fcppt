//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_FOR_EACH_BREAK_HPP_INCLUDED
#define FCPPT_MPL_FOR_EACH_BREAK_HPP_INCLUDED

#include <fcppt/mpl/detail/for_each_break.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Invoke a function on each element of a sequence without constructing
them and giving the ability to break out of the loop

\ingroup fcpptmpl

Similar to fcppt::mpl::for_each, but can break out of a loop early.

\see fcppt::mpl::for_each

\tparam Function The polymorphic function callable as <code>fcppt::loop
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
		fcppt::mpl::detail::for_each_break<
			typename
			boost::mpl::begin<
				Sequence
			>::type,
			typename
			boost::mpl::end<
				Sequence
			>::type
		>(
			_function
		);
}

}
}

#endif
