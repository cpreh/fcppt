//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_CUSTOM_ERROR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_CUSTOM_ERROR_DECL_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/parse/custom_error_fwd.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
template <typename Ch>
class custom_error
{
public:
  using pos_type = fcppt::parse::position<Ch>;

  using string_type = std::basic_string<Ch>;

  custom_error(pos_type, string_type &&);

  [[nodiscard]] pos_type pos() const;

  [[nodiscard]] string_type const &message() const;

  [[nodiscard]] bool operator==(custom_error const &) const;
private:
  pos_type pos_;

  string_type message_;
};

}

#endif
