//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_FOR_EACH_HPP_INCLUDED
#define FCPPT_MPL_FOR_EACH_HPP_INCLUDED

#include <fcppt/mpl/detail/for_each.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/end.hpp>
#include <fcppt/config/external_end.hpp>


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

\snippet mpl/for_each.cpp mpl_for_each

\tparam Sequence The MPL sequence

\tparam Functor The functor type which must be callable with every element
*/
template<
	typename Sequence,
	typename Function
>
void
for_each(
	Function const &_function
)
{
	return
		fcppt::mpl::detail::for_each<
			boost::mpl::empty<
				Sequence
			>::value
		>:: template execute<
			typename boost::mpl::begin<
				Sequence
			>::type,
			typename boost::mpl::end<
				Sequence
			>::type
		>(
			_function
		);
}

}
}

#endif
