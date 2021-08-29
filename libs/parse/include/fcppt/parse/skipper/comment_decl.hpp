//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_COMMENT_DECL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_COMMENT_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/skipper/comment_fwd.hpp>
#include <fcppt/parse/skipper/result_fwd.hpp>
#include <fcppt/parse/skipper/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::skipper
{
template <typename Open, typename Close>
class comment : private fcppt::parse::skipper::tag
{
public:
  comment(Open &&, Close &&);

  template <typename Ch>
  [[nodiscard]] fcppt::parse::skipper::result<Ch>
      skip(fcppt::reference<fcppt::parse::basic_stream<Ch>>) const;

private:
  Open open_;

  Close close_;
};

template <typename Open, typename Close>
comment(Open &&, Close &&) -> comment<std::remove_cvref_t<Open>, std::remove_cvref_t<Close>>;
}

#endif
