//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_CONSUME_REMAINING_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_CONSUME_REMAINING_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/construct.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/map_failure.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/io/stream_to_string.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/parse/parse_stream_error_impl.hpp>
#include <fcppt/parse/parse_string_error_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::detail
{

template <typename Ch, typename Result>
[[nodiscard]] fcppt::either::object<fcppt::parse::parse_string_error<Ch>, Result> consume_remaining(
    fcppt::reference<std::basic_istream<Ch>> const _stream,
    fcppt::either::object<fcppt::parse::parse_stream_error<Ch>, Result> &&_result)
{
  return fcppt::either::bind(
      fcppt::either::map_failure(
          std::move(_result),
          [&_stream](fcppt::parse::parse_stream_error<Ch> &&_failure)
          {
            return fcppt::parse::parse_string_error<Ch>{
                std::move(_failure), fcppt::io::stream_to_string(_stream.get())};
          }),
      [&_stream](Result &&_success)
      {
        return fcppt::optional::maybe(
            fcppt::io::stream_to_string(_stream.get()),
            []
            { return fcppt::either::make_failure<Result>(fcppt::parse::parse_string_error<Ch>{}); },
            [&_success](std::basic_string<Ch> &&_rest)
            {
              return fcppt::either::construct(
                  _rest.empty(),
                  [&_success] { return std::move(_success); },
                  [&_rest] { return fcppt::parse::parse_string_error<Ch>{std::move(_rest)}; });
            });
      });
}
}

#endif
