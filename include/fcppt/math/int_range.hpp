//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_INT_RANGE_HPP_INCLUDED
#define FCPPT_MATH_INT_RANGE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/range_c.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

template<
	fcppt::math::size_type Start,
	fcppt::math::size_type Count
>
using
int_range
=
boost::mpl::range_c<
	fcppt::math::size_type,
	Start,
	Start
	+
	Count
>;

}
}

#endif
