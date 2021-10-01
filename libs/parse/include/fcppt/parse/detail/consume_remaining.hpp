//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_CONSUME_REMAINING_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_CONSUME_REMAINING_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/io/stream_to_string.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::detail
{
template <typename Ch, typename Type>
[[nodiscard]] fcppt::parse::result<Ch, Type> consume_remaining(
    fcppt::reference<std::basic_istream<Ch>> const _stream,
    fcppt::parse::result<Ch, Type> &&_result)
{
  using result_type = fcppt::parse::result<Ch, Type>;

  return fcppt::either::match(
      std::move(_result),
      [&_stream](fcppt::parse::error<Ch> &&_failure) {
        return result_type{
            std::move(_failure) + fcppt::parse::error<Ch>{
                                      FCPPT_STRING_LITERAL(Ch, ". Remaining input: \"") +
                                      fcppt::optional::from(
                                          fcppt::io::stream_to_string(_stream.get()),
                                          [] {
                                            return std::basic_string<Ch>{FCPPT_STRING_LITERAL(
                                                Ch, "Failed to read remaining input!")};
                                          }) +
                                      FCPPT_STRING_LITERAL(Ch, "\"")}};
      },
      [&_stream](Type &&_success) {
        return fcppt::optional::maybe(
            fcppt::io::stream_to_string(_stream.get()),
            [] {
              return result_type{fcppt::parse::error<Ch>{
                  FCPPT_STRING_LITERAL(Ch, "Failed to read remaining input.")}};
            },
            [&_success](std::basic_string<Ch> &&_rest) {
              return _rest.empty()
                         ? result_type{std::move(_success)}
                         : result_type{fcppt::parse::error<Ch>{
                               FCPPT_STRING_LITERAL(Ch, "Failed to consume remaining input: \"") +
                               std::move(_rest) + FCPPT_STRING_LITERAL(Ch, "\"")}};
            });
      });
}

}

#endif
