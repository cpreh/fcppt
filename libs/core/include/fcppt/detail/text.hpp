//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_TEXT_HPP_INCLUDED
#define FCPPT_DETAIL_TEXT_HPP_INCLUDED

#include <fcppt/public_config.hpp>


#if defined(FCPPT_NARROW_STRING)
#define FCPPT_DETAIL_TEXT(x) x
#else
#define FCPPT_DETAIL_TEXT(x) L ## x
#endif

#endif
