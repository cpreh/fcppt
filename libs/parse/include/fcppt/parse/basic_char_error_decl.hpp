//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_CHAR_ERROR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_ERROR_DECL_HPP_INCLUDED

#include <fcppt/parse/basic_char_error_fwd.hpp>
#include <fcppt/parse/position.hpp>

namespace fcppt::parse
{
template <typename Ch>
class basic_char_error
{
public:
  using pos_type = fcppt::parse::position<Ch>;

  explicit basic_char_error(pos_type);

  [[nodiscard]] pos_type pos() const;

  [[nodiscard]] bool operator==(basic_char_error const &) const = default;
private:
  pos_type pos_;
};

}

#endif
