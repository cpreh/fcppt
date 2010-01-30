//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/random/exclusive_range_error.hpp>

fcppt::random::exclusive_range_error::exclusive_range_error(
	fcppt::string const &s
)
:
	exception(s)
{}
