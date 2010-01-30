//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_FOR_EACH_HPP_INCLUDED
#define FCPPT_MPL_FOR_EACH_HPP_INCLUDED

#include <fcppt/mpl/detail/for_each.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/empty.hpp>

namespace fcppt
{
namespace mpl
{

template<
	typename Sequence,
	typename Fun
>
void
for_each(
	Fun const &f
)
{
	return
		detail::for_each<
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
			f
		);
}

}
}

#endif
