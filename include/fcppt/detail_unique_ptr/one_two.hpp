// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_DETAIL_UNIQUE_PTR_ONE_TWO_HPP_INCLUDED
#define FCPPT_DETAIL_UNIQUE_PTR_ONE_TWO_HPP_INCLUDED

namespace fcppt
{
namespace detail_unique_ptr
{

typedef char one;

struct two
{
	one _[2];
};

}
}

#endif
