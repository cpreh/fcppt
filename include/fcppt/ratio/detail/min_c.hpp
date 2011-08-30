//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2011 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_DETAIL_MIN_C_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_MIN_C_HPP_INCLUDED

#include <fcppt/ratio/int_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <climits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace ratio
{
namespace detail
{

int_type const min_c =
	(static_cast<int_type>(1)
	<< (sizeof(int_type) * CHAR_BIT - 1)) + 1;

}
}
}

#endif
