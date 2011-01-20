//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2011 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_FEMTO_HPP_INCLUDED
#define FCPPT_RATIO_FEMTO_HPP_INCLUDED

#include <fcppt/config.hpp>
#ifdef FCPPT_HAVE_LONG_LONG
#include <fcppt/ratio/object_fwd.hpp>

namespace fcppt
{
namespace ratio
{

typedef object<
	1,
	1000000000000000LL
> femto;

}
}
#endif

#endif
