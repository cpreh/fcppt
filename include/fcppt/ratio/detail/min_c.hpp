//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2011 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_DETAIL_MIN_C_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_MIN_C_HPP_INCLUDED

#include <fcppt/ratio/int_type.hpp>
#include <fcppt/mpl/integral_c.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/integer_traits.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace ratio
{
namespace detail
{

typedef fcppt::mpl::integral_c<
	ratio::int_type,
	boost::integer_traits<
		ratio::int_type
	>::const_min
	+ 1 // leave room for NaN
> min_c;

}
}
}

#endif
