//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DETAIL_MAIN_HPP_INCLUDED
#define FCPPT_DETAIL_MAIN_HPP_INCLUDED

#include <fcppt/detail/main_wchar.hpp> // IWYU pragma: keep

#if defined(FCPPT_DETAIL_MAIN_WCHAR)
#define FCPPT_DETAIL_MAIN wmain
#else
#define FCPPT_DETAIL_MAIN main
#endif

#endif
