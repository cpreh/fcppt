//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/cout.hpp>
#include <fcppt/config.hpp>
#include <iostream>

fcppt::io::ostream &
fcppt::io::cout(
#ifndef FCPPT_NARROW_STRING
	std::wcout
#else
	std::cout
#endif
);
