//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_MAX_VALUE_HPP_INCLUDED
#define FCPPT_MPL_MAX_VALUE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/max_element.hpp>
#include <boost/mpl/transform.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace mpl
{

/// Calculates the maximum value in @a Sequence
/**
 * @tparam Sequence An MPL sequence
 * @tparam Pred The predicate to use on each element. It has to return an integral wrapper type.
 * @return The maximum element
*/
template<
	typename Sequence,
	typename Pred
>
struct max_value
:
boost::mpl::deref<
	typename boost::mpl::max_element<
		typename boost::mpl::transform<
			Sequence,
			Pred
		>::type
	>::type
>::type
{};

}
}

#endif
