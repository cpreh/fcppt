//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UTF8_TO_FCPPT_STRING_HPP_INCLUDED
#define FCPPT_UTF8_TO_FCPPT_STRING_HPP_INCLUDED

#include <fcppt/utf8/string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace utf8
{

FCPPT_SYMBOL
fcppt::string const
to_fcppt_string(
	utf8::string const &
);

}
}

#endif
