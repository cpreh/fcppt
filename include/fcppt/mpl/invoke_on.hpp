//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INVOKE_ON_HPP_INCLUDED
#define FCPPT_MPL_INVOKE_ON_HPP_INCLUDED

#include <fcppt/mpl/detail/invoke_on.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/integral_c.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Applies a functor to the nth element of a sequence with a runtime index

\ingroup fcpptmpl

Applies \a _functor to the nth element (where n is denoted by \a _index) of the
sequence \a Sequence. This can be useful if you have a runtime index into an
MPL sequence and you want to invoke something on that type.

\note The compile time and the runtime complexities of this function are linear
in the size of the MPL sequence

\snippet mpl/invoke_on.cpp mpl_invoke_on

\tparam Sequence An MPL sequence

\tparam Index An integral type

\param _index The runtime index of type \a Index

\param _functor The functor to invoke

\return The result of <code>_functor<T>()</code> if <code>T</code> is the
element of \a Sequence at \a _index

\throw invalid_invoke if \a _index is out of range
*/
template<
	typename Sequence,
	typename Index,
	typename Functor
>
typename Functor::result_type
invoke_on(
	Index const &_index,
	Functor const &_functor
)
{
	return
		fcppt::mpl::detail::invoke_on<
			boost::mpl::integral_c<
				unsigned,
				0u
			>,
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
			_index,
			_functor
		);
}

}
}

#endif
