//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_ANY_DECL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_ANY_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/skipper/any_fwd.hpp> // IWYU pragma: keep
#include <fcppt/parse/skipper/result_fwd.hpp>
#include <fcppt/parse/skipper/tag.hpp>

namespace fcppt::parse::skipper
{
/**
\brief Skips a single character.
\ingroup fcpptparse
*/
class any : private fcppt::parse::skipper::tag
{
public:
  any();

  template <typename Ch>
  [[nodiscard]] fcppt::parse::skipper::result<Ch>
      skip(fcppt::reference<fcppt::parse::basic_stream<Ch>>) const;
};

}

#endif
