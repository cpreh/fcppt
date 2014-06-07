//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_COLOR_ATTRIBUTE_HPP_INCLUDED
#define FCPPT_IO_COLOR_ATTRIBUTE_HPP_INCLUDED

#include <fcppt/io/color/attribute_fwd.hpp>


namespace fcppt
{
namespace io
{
namespace color
{

enum class attribute
{
	off = 0,
	bold = 1,
	underscore = 4,
	blink = 5,
	reverse = 7,
	concealed = 8
};

}
}
}

#endif
