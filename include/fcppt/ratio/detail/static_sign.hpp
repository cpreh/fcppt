//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2011 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_DETAIL_STATIC_SIGN_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_STATIC_SIGN_HPP_INCLUDED

#include <fcppt/ratio/int_type.hpp>

namespace fcppt
{
namespace ratio
{
namespace detail
{

template<
	int_type X
>
struct static_sign
{
	static int_type const value = X == 0 ? 0 : (X < 0 ? -1 : 1);
};

}
}
}

#endif
