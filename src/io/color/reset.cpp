//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/color/reset.hpp>

fcppt::io::color::set const
fcppt::io::color::reset()
{
	return
		set(
			foreground::off,
			background::off,
		attribute::off);
}
