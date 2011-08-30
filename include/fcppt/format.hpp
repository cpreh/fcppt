//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FORMAT_HPP_INCLUDED
#define FCPPT_FORMAT_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/format.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

typedef boost::basic_format<
	char_type
> format;

}

#endif
