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
