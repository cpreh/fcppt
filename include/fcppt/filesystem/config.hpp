//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_CONFIG_HPP_INCLUDED
#define FCPPT_FILESYSTEM_CONFIG_HPP_INCLUDED

#include <boost/version.hpp>

#if (BOOST_VERSION >= 104400)
#define FCPPT_USE_FILESYSTEM_V3
#define BOOST_FILESYSTEM_VERSION 3
#endif

#endif
