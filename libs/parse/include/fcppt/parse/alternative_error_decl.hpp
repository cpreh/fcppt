//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_ALTERNATIVE_ERROR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_ALTERNATIVE_ERROR_DECL_HPP_INCLUDED

#include <fcppt/recursive_comparison.hpp>
#include <fcppt/recursive_impl.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/parse/alternative_error_fwd.hpp>
#include <fcppt/parse/error_fwd.hpp>
#include <fcppt/parse/left_error_tag_fwd.hpp>
#include <fcppt/parse/right_error_tag_fwd.hpp>

namespace fcppt::parse
{
template <typename Ch>
class alternative_error
{
public:
  using error_base = fcppt::recursive<fcppt::parse::error<Ch>>;

  using left_type = fcppt::strong_typedef<error_base, fcppt::parse::left_error_tag>;
  using right_type = fcppt::strong_typedef<error_base, fcppt::parse::right_error_tag>;

  // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
  alternative_error(left_type &&, right_type &&);

  [[nodiscard]] error_base const &left() const;

  [[nodiscard]] error_base const &right() const;

  [[nodiscard]] bool operator==(alternative_error const &) const = default;
private:
  error_base left_;

  error_base right_;
};

}

#endif
