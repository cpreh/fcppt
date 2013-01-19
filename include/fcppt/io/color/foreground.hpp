//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_COLOR_FOREGROUND_HPP_INCLUDED
#define FCPPT_IO_COLOR_FOREGROUND_HPP_INCLUDED

#include <fcppt/io/color/foreground_fwd.hpp>


namespace fcppt
{
namespace io
{
namespace color
{

enum class foreground
{
	off = 0,
	black = 30,
	red = 31,
	green = 32,
	yellow = 33,
	blue = 34,
	magenta = 35,
	cyan = 36,
	white = 37
};

}
}
}

#endif
