//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_CHAR_SET_ERROR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_SET_ERROR_DECL_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/basic_char_set_container.hpp>
#include <fcppt/parse/basic_char_set_error_fwd.hpp>
#include <fcppt/parse/got_tag_fwd.hpp>
#include <fcppt/parse/position.hpp>

namespace fcppt::parse
{
template <typename Ch>
class basic_char_set_error
{
public:
  using char_set_type = fcppt::parse::basic_char_set_container<Ch>;

  using pos_type = fcppt::parse::position<Ch>;

  using got_type = fcppt::strong_typedef<fcppt::optional::object<Ch>, fcppt::parse::got_tag>;

  basic_char_set_error(pos_type, char_set_type &&, got_type);

  [[nodiscard]] pos_type const &pos() const;

  [[nodiscard]] char_set_type const &chars() const;

  [[nodiscard]] fcppt::optional::object<Ch> const &got() const;

  [[nodiscard]] bool operator==(basic_char_set_error const &) const = default;
private:
  pos_type pos_;

  char_set_type chars_;

  fcppt::optional::object<Ch> got_;
};

}

#endif
