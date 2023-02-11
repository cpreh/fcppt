//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_STRING_ERROR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_STRING_ERROR_DECL_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/parse/basic_string_error_fwd.hpp>
#include <fcppt/parse/expected_tag_fwd.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
template <typename Ch>
class basic_string_error
{
public:
  using pos_type = fcppt::parse::position<Ch>;

  using string_type = std::basic_string<Ch>;

  using expected_type = fcppt::strong_typedef<string_type, fcppt::parse::expected_tag>;

  basic_string_error(pos_type, expected_type &&);

  [[nodiscard]] pos_type pos() const;

  [[nodiscard]] string_type const &expected() const;

  [[nodiscard]] bool operator==(basic_string_error const &) const = default;
private:
  pos_type pos_;

  string_type expected_;
};

}

#endif
