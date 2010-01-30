//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FORMAT_HPP_INCLUDED
#define FCPPT_FORMAT_HPP_INCLUDED

#include <fcppt/config.h>
#include <boost/format.hpp>

namespace fcppt
{

#ifdef FCPPT_NARROW_STRING
typedef boost::format format;
#else
typedef boost::wformat format;
#endif

}

#endif
