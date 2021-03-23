//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MAIN_HPP_INCLUDED
#define FCPPT_MAIN_HPP_INCLUDED

#include <fcppt/detail/main.hpp>

/**
\brief The name of the main function.

\ingroup fcpptvarious

Windows uses <code>wmain</code> instead of <code>main</code> for Unicode applications.
The type of this function is <code>int (int,fcppt::args_char **)</code>.

\note This must be used together with <code>FCPPT_UTILS_MAIN_COMPILE_OPTIONS</code> and
<code>FCPPT_UTILS_MAIN_LINK_LIBS</code>.
*/
#define FCPPT_MAIN FCPPT_DETAIL_MAIN

#endif
