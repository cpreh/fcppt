//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IO_NARROW_STRING_LOCALE_HPP_INCLUDED
#define FCPPT_IO_NARROW_STRING_LOCALE_HPP_INCLUDED

#include <fcppt/algorithm/map.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <string_view>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::io
{
/**
\brief Uses narrow on every character.
\ingroup fcpptio
Let <code>_string = c_1 ... c_n</code> and <code>d_i = narrow(c_i,0)</code> for <code>i = 1,...,n</code>,
where <code>narrow</code> is the function from <code>std::ctype<Ch></code>.
Then this function returns the string <code>d_1, ..., d_n</code> if and only if <code>d_i != 0</code> for <code>i = 1,...,n</code>.
*/
template <typename Ch, typename Traits>
fcppt::optional::object<std::string>
narrow_string_locale(std::basic_string_view<Ch, Traits> const _string, std::locale const &_locale)
{
  auto const &facet{std::use_facet<std::ctype<Ch>>(_locale)};

  std::string result{fcppt::algorithm::map<std::string>(
      _string, [&facet](Ch const _ch) { return facet.narrow(_ch, '\0'); })};

  return fcppt::optional::make_if(!result.contains('\0'), [&result] { return std::move(result); });
}
}

#endif
