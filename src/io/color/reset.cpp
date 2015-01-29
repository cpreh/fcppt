//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/color/attribute.hpp>
#include <fcppt/io/color/background.hpp>
#include <fcppt/io/color/foreground.hpp>
#include <fcppt/io/color/set.hpp>
#include <fcppt/io/color/reset.hpp>


fcppt::io::color::set const
fcppt::io::color::reset()
{
	return
		fcppt::io::color::set(
			fcppt::io::color::foreground::off,
			fcppt::io::color::background::off,
			fcppt::io::color::attribute::off
		);
}
