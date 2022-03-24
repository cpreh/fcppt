//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EXTRACT_FROM_STRING_LOCALE_FMT_HPP_INCLUDED
#define FCPPT_EXTRACT_FROM_STRING_LOCALE_FMT_HPP_INCLUDED

#include <fcppt/concepts/string.hpp>
#include <fcppt/io/extract.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/nothing.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_gnu_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <locale>
#include <sstream>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Convert a string to a different type using a locale.

\ingroup fcpptstring

\tparam Dest The destination type, has to have an <code>operator>></code> defined. Must
have either a default constructor or must be constructible from #fcppt::no_init.

\tparam Source A string type (see #fcppt::type_traits::is_string)

\note The string has to be consumed completely.
*/
template <typename Dest, fcppt::concepts::string Source>
fcppt::optional::object<Dest> extract_from_string_locale_fmt(
    Source &&_source,
    std::locale const &_locale,
    fcppt::optional::object<std::ios_base::fmtflags> const _flags)
{
  using source = std::remove_cvref_t<Source>;

  using traits = typename source::traits_type;

  using istringstream = std::basic_istringstream<fcppt::type_traits::value_type<source>, traits>;

  istringstream iss{std::forward<Source>(_source)};

  iss.imbue(_locale);

  fcppt::optional::maybe_void(
      _flags, [&iss](std::ios_base::fmtflags const &_inner_flags) { iss.setf(_inner_flags); });

  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GNU_GCC_WARNING(-Wmaybe-uninitialized)
  fcppt::optional::object<Dest> result{fcppt::io::extract<Dest>(iss)};

  return iss.peek() == traits::eof() ? std::move(result) : fcppt::optional::nothing{};
  FCPPT_PP_POP_WARNING
}
}

#endif
