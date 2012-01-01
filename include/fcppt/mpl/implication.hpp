//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_IMPLICATION_HPP_INCLUDED
#define FCPPT_MPL_IMPLICATION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/or.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/// The Implication function: @a Left -> @a Right
/**
 * @tparam Left A boolean expression
 * @tparam Right A boolean expression
 * @remarks Equal to (not @a Left) or @a Right
*/
template<
	typename Left,
	typename Right
>
struct implication
:
boost::mpl::or_<
	boost::mpl::not_<
		Left
	>,
	Right
>
{};

}
}

#endif
