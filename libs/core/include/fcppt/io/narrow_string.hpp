//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IO_NARROW_STRING_HPP_INCLUDED
#define FCPPT_IO_NARROW_STRING_HPP_INCLUDED

#include <fcppt/io/narrow_string_locale.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <string>
#include <string_view>
#include <fcppt/config/external_end.hpp>

namespace fcppt::io
{
/**
\brief Uses narrow on every character.
\ingroup fcpptio
Calls #fcppt::io::narrow_string_locale using the locale from \a _ios.
*/
template <typename Ch, typename Traits>
inline fcppt::optional::object<std::string> narrow_string(
    std::basic_ios<Ch, Traits> const &_ios, std::basic_string_view<Ch, Traits> const _string)
{
  return fcppt::io::narrow_string_locale(_string, _ios.getloc());
}
}

#endif
