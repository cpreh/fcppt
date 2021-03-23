//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_EPSILON_DECL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_EPSILON_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/skipper/epsilon_fwd.hpp>
#include <fcppt/parse/skipper/result_fwd.hpp>
#include <fcppt/parse/skipper/tag.hpp>

namespace fcppt
{
namespace parse
{
namespace skipper
{
/**
\brief Skips nothing.
\ingroup fcpptparse
*/
class epsilon : private fcppt::parse::skipper::tag
{
public:
  epsilon();

  template <typename Ch>
  [[nodiscard]] fcppt::parse::skipper::result<Ch>
      skip(fcppt::reference<fcppt::parse::basic_stream<Ch>>) const;
};

}
}
}

#endif
