//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_LOCATION_DECL_HPP_INCLUDED
#define FCPPT_PARSE_LOCATION_DECL_HPP_INCLUDED

#include <fcppt/parse/column.hpp>
#include <fcppt/parse/line.hpp>
#include <fcppt/parse/location_fwd.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief The location of a #fcppt::parse::basic_stream.

A location consists of a line number and a column number.
*/
class location
{
public:
  location(fcppt::parse::line, fcppt::parse::column);

  [[nodiscard]] fcppt::parse::line line() const;

  [[nodiscard]] fcppt::parse::line &line();

  [[nodiscard]] fcppt::parse::column column() const;

  [[nodiscard]] fcppt::parse::column &column();

private:
  fcppt::parse::line line_;

  fcppt::parse::column column_;
};

}
}

#endif
