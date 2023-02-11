//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_LITERAL_ERROR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_LITERAL_ERROR_DECL_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/basic_literal_error_fwd.hpp>
#include <fcppt/parse/expected_tag_fwd.hpp>
#include <fcppt/parse/got_tag_fwd.hpp>
#include <fcppt/parse/position.hpp>

namespace fcppt::parse
{
template <typename Ch>
class basic_literal_error
{
public:
  using pos_type = fcppt::parse::position<Ch>;

  using expected_type = fcppt::strong_typedef<Ch, fcppt::parse::expected_tag>;

  using got_type = fcppt::strong_typedef<fcppt::optional::object<Ch>, fcppt::parse::got_tag>;

  basic_literal_error(pos_type, expected_type, got_type);

  [[nodiscard]] pos_type pos() const;

  [[nodiscard]] Ch expected() const;

  [[nodiscard]] fcppt::optional::object<Ch> const &got() const;

  [[nodiscard]] bool operator==(basic_literal_error const &) const = default;
private:
  pos_type pos_;

  Ch expected_;

  fcppt::optional::object<Ch> got_;
};

}

#endif
