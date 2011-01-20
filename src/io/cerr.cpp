//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/cerr.hpp>
#include <fcppt/config.hpp>
#include <iostream>

fcppt::io::ostream &
fcppt::io::cerr(
#ifndef FCPPT_NARROW_STRING
	std::wcerr
#else
	std::cerr
#endif
);
