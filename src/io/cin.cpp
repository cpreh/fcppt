//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/cin.hpp>
#include <fcppt/config.hpp>
#include <iostream>

fcppt::io::istream &
fcppt::io::cin(
#ifndef FCPPT_NARROW_STRING
	std::wcin
#else
	std::cin
#endif
);
