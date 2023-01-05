//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_NAMED_ERROR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_NAMED_ERROR_DECL_HPP_INCLUDED

#include <fcppt/recursive_impl.hpp>
#include <fcppt/parse/error_fwd.hpp>
#include <fcppt/parse/named_error_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
template <typename Ch>
class named_error
{
public:
  using error_base = fcppt::recursive<fcppt::parse::error<Ch>>;

  using string_type = std::basic_string<Ch>;

  named_error(string_type &&, error_base &&);

  [[nodiscard]] string_type const &name() const;

  [[nodiscard]] error_base const &error() const;

  [[nodiscard]] bool operator==(named_error const &) const;
private:
  string_type name_;

  error_base error_;
};

}

#endif
