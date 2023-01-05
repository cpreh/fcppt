//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_EXCEPTION_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_EXCEPTION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::detail
{
template <typename Ch>
class exception
{
public:
  explicit exception(std::basic_string<Ch> &&_what) : what_{std::move(_what)} {}

  [[nodiscard]] std::basic_string<Ch> const &what() const { return this->what_; }
private:
  std::basic_string<Ch> what_;
};

}

#endif
