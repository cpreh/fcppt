//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_EPSILON_DECL_HPP_INCLUDED
#define FCPPT_PARSE_EPSILON_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/unit_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/epsilon_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/tag.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief Parses the empty string, returns nothing.
\ingroup fcpptparse
*/
class epsilon : private fcppt::parse::tag
{
public:
  epsilon();

  using result_type = fcppt::unit;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;
};

}
}

#endif
