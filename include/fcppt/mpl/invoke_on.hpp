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

/// Apply the function @a fun on the nth element @a index in @a Sequence
/**
 * @tparam Sequence An MPL sequence
 * @param index A runtime index of the element to invoke the functor on
 * @param fun The functor
 * @return The result of @a fun<T>() if T is the element of @a Sequence at @a index
 * @throws invalid_invoke if @a index is out of range
*/
template<
	typename Sequence,
	typename Function,
	typename Index
>
typename Function::result_type
invoke_on(
	Index const &index,
	Function const &fun
)
{
	return detail::invoke_on<
		boost::mpl::integral_c<
			Index,
			0
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
		index,
		fun
	);
}

}
}

#endif
