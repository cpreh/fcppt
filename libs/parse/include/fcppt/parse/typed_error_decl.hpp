//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_TYPED_ERROR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_TYPED_ERROR_DECL_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/parse/got_tag_fwd.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/type_name_tag_fwd.hpp>
#include <fcppt/parse/typed_error_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
template <typename Ch>
class typed_error
{
public:
  using pos_type = fcppt::parse::position<Ch>;

  using string_type = std::basic_string<Ch>;

  using type_name_type = fcppt::strong_typedef<string_type, fcppt::parse::type_name_tag>;

  using got_type = fcppt::strong_typedef<string_type, fcppt::parse::got_tag>;

  typed_error(pos_type, type_name_type &&, got_type &&);

  [[nodiscard]] pos_type pos() const;

  [[nodiscard]] string_type const &type_name() const;

  [[nodiscard]] string_type const &got() const;

  [[nodiscard]] bool operator==(typed_error const &) const = default;
private:
  pos_type pos_;

  string_type type_name_;

  string_type got_;
};

}

#endif
