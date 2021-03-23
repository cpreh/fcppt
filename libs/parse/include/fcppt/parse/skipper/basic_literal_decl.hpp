//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_BASIC_LITERAL_DECL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_BASIC_LITERAL_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/is_char.hpp>
#include <fcppt/parse/skipper/basic_literal_fwd.hpp>
#include <fcppt/parse/skipper/result_fwd.hpp>
#include <fcppt/parse/skipper/tag.hpp>

namespace fcppt
{
namespace parse
{
namespace skipper
{
/**
\brief Skips a specific character.
\ingroup fcpptparse
*/
template <typename Ch>
class basic_literal : private fcppt::parse::skipper::tag
{
public:
  static_assert(fcppt::parse::is_char<Ch>::value);

  explicit basic_literal(Ch);

  [[nodiscard]] fcppt::parse::skipper::result<Ch>
      skip(fcppt::reference<fcppt::parse::basic_stream<Ch>>) const;

private:
  Ch ch_;
};

}
}
}

#endif
