//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2011 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_LESS_EQUAL_HPP_INCLUDED
#define FCPPT_RATIO_LESS_EQUAL_HPP_INCLUDED

#include <fcppt/ratio/less_equal_fwd.hpp>
#include <fcppt/ratio/less.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace fcppt
{
namespace ratio
{

template<
	typename R1,
	typename R2
>
struct less_equal
:
boost::integral_constant<
	bool,
	!less<R2, R1>::value
>
{};

}
}

#endif
