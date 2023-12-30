//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_PARSE_STRING_ERROR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_STRING_ERROR_DECL_HPP_INCLUDED

#include <fcppt/optional/comparison.hpp> // IWYU pragma: keep
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/parse_stream_error_impl.hpp>
#include <fcppt/parse/parse_string_error_fwd.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{

template<typename Ch>
class parse_string_error
{
public:
  using optional_string = fcppt::optional::object<std::basic_string<Ch>>;

  using optional_stream_error = fcppt::optional::object<fcppt::parse::parse_stream_error<Ch>>;

  parse_string_error(fcppt::parse::parse_stream_error<Ch> &&, optional_string &&);
  explicit parse_string_error(std::basic_string<Ch> &&);
  parse_string_error(); // TODO(philipp)

  [[nodiscard]] optional_stream_error const &stream_error() const;

  [[nodiscard]] optional_string const &rest() const;

  [[nodiscard]] bool operator==(parse_string_error const &) const = default;
private:
  optional_stream_error stream_error_;

  optional_string rest_;
};

}

#endif
