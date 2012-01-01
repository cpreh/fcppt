//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UTF8_LOCALE_HPP_INCLUDED
#define FCPPT_UTF8_LOCALE_HPP_INCLUDED

#include <fcppt/config.hpp>
#ifndef FCPPT_STRING_IS_UTF8
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace utf8
{

std::locale &
locale();

}
}
#endif

#endif
