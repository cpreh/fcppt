//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UTF8_STRING_HPP_INCLUDED
#define FCPPT_UTF8_STRING_HPP_INCLUDED

#include <fcppt/utf8/char_type.hpp>
#include <fcppt/utf8/traits.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace utf8
{

/// The utf-8 string type
typedef std::basic_string<
	char_type,
	traits
> string;

}
}

#endif
