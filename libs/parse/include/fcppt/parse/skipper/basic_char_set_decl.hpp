//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_BASIC_CHAR_SET_DECL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_BASIC_CHAR_SET_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_char_set_container.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/skipper/basic_char_set_fwd.hpp> // IWYU pragma: keep
#include <fcppt/parse/skipper/result_fwd.hpp>
#include <fcppt/parse/skipper/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::skipper
{
/**
\brief Skips all characters from a set.
\ingroup fcpptparse
*/
template <typename Ch>
class basic_char_set : private fcppt::parse::skipper::tag
{
public:
  using char_set_type = fcppt::parse::basic_char_set_container<Ch>;

  basic_char_set(std::initializer_list<Ch> const &);

  explicit basic_char_set(char_set_type &&);

  [[nodiscard]] fcppt::parse::skipper::result<Ch>
      skip(fcppt::reference<fcppt::parse::basic_stream<Ch>>) const;

  [[nodiscard]] char_set_type const &chars() const;

private:
  char_set_type chars_;
};

}

#endif
