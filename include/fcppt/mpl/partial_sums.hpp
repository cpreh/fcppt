//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_PARTIAL_SUMS_HPP_INCLUDED
#define FCPPT_MPL_PARTIAL_SUMS_HPP_INCLUDED

#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/placeholders.hpp>

namespace fcppt
{
namespace mpl
{

template<
	typename Elements
>
struct partial_sums
:
boost::mpl::fold<
	Elements,
	boost::mpl::vector_c<int, 0>, // mpl::plus<> converts its operands, so int is most conservative
	boost::mpl::push_back<
		boost::mpl::_1,
		boost::mpl::plus<
			boost::mpl::back<
				boost::mpl::_1
			>,
			boost::mpl::_2
		>
	>
> {};

}
}

#endif
