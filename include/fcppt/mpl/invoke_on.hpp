//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INVOKE_ON_HPP_INCLUDED
#define FCPPT_MPL_INVOKE_ON_HPP_INCLUDED

#include <fcppt/mpl/detail/invoke_on.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/empty.hpp>

namespace fcppt
{
namespace mpl
{

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
