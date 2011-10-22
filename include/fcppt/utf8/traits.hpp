//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UTF8_TRAITS_HPP_INCLUDED
#define FCPPT_UTF8_TRAITS_HPP_INCLUDED

#include <fcppt/utf8/char_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace utf8
{

/// A new traits type, so that strings don't get accidentally converted into utf-8 strings
class traits
:
public std::char_traits<
	utf8::char_type
>
{};

}
}

#endif
