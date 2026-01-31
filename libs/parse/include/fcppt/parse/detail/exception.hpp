//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_EXCEPTION_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_EXCEPTION_HPP_INCLUDED

#include <fcppt/parse/stream_error.hpp>

namespace fcppt::parse::detail
{
class exception
{
public:
  explicit exception(fcppt::parse::stream_error const _what) : what_{_what} {}

  [[nodiscard]] fcppt::parse::stream_error what() const { return this->what_; }
private:
  fcppt::parse::stream_error what_;
};

}

#endif
