//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_MAX_VALUE_HPP_INCLUDED
#define FCPPT_MPL_MAX_VALUE_HPP_INCLUDED

#include <boost/mpl/deref.hpp>
#include <boost/mpl/max_element.hpp>
#include <boost/mpl/transform.hpp>

namespace fcppt
{
namespace mpl
{

template<
	typename Elements,
	typename Pred
>
struct max_value
:
boost::mpl::deref<
	typename boost::mpl::max_element<
		typename boost::mpl::transform<
			Elements,
			Pred
		>::type
	>::type
>::type
{};

}
}

#endif
