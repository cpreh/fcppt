//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EXTRACT_FROM_STRING_HPP_INCLUDED
#define FCPPT_EXTRACT_FROM_STRING_HPP_INCLUDED

#include <fcppt/extract_from_string_locale_fmt.hpp>
#include <fcppt/insert_extract_locale.hpp>
#include <fcppt/concepts/string.hpp> // IWYU pragma: keep
#include <fcppt/optional/nothing.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Convert a string to a different type using #fcppt::insert_extract_locale.

\ingroup fcpptstring

\tparam Dest The destination type, has to have an <code>operator>></code> defined. Must
have either a default constructor or must be constructible from #fcppt::no_init.

\param _source The string to extract from

\note The string has to be consumed completely.
*/
template <typename Dest, fcppt::concepts::string Source>
inline fcppt::optional::object<Dest> extract_from_string(Source &&_source)
{
  return fcppt::extract_from_string_locale_fmt<Dest>(
      std::forward<Source>(_source), fcppt::insert_extract_locale(), fcppt::optional::nothing{});
}
}

#endif
