//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TEST_PARSE_SKIPPER_SKIP_STRING_HPP_INCLUDED
#define FCPPT_TEST_PARSE_SKIPPER_SKIP_STRING_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/either/error.hpp>
#include <fcppt/either/map_failure.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/parse/basic_stream_impl.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/parse_stream_error.hpp>
#include <fcppt/parse/parse_string_error.hpp>
#include <fcppt/parse/detail/consume_remaining.hpp>
#include <fcppt/parse/detail/exception.hpp>
#include <fcppt/parse/detail/stream_impl.hpp>
#include <fcppt/parse/detail/translate_exception.hpp>
#include <fcppt/parse/skipper/is_skipper_v.hpp>
#include <fcppt/parse/skipper/make_failure.hpp>
#include <fcppt/parse/skipper/run.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <istream>
#include <sstream>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt::test::parse::skipper
{

template <typename Ch, typename Skipper>
[[nodiscard]] fcppt::either::error<fcppt::parse::parse_string_error<Ch>>
skip_string(Skipper const &_skipper, std::basic_string<Ch> &&_string)
{
  static_assert(fcppt::parse::skipper::is_skipper_v<Skipper>);

  std::basic_istringstream<Ch> string_stream{std::move(_string)};

  string_stream.unsetf(std::ios_base::skipws);

  fcppt::parse::detail::stream<Ch> stream{
      fcppt::reference_to_base<std::basic_istream<Ch>>(fcppt::make_ref(string_stream))};

  return fcppt::parse::detail::consume_remaining(
      fcppt::reference_to_base<std::basic_istream<Ch>>(fcppt::make_ref(string_stream)),
      [&_skipper, &stream]
      {
        try
        {
          return fcppt::either::map_failure(
              fcppt::parse::skipper::run(
                  _skipper,
                  fcppt::reference_to_base<fcppt::parse::basic_stream<Ch>>(
                      fcppt::make_ref(stream))),
              [](fcppt::parse::error<Ch> &&_inner)
              { return fcppt::parse::parse_stream_error<Ch>{std::move(_inner)}; });
        }
        catch (fcppt::parse::detail::exception<Ch> const &_error)
        {
          return fcppt::parse::detail::translate_exception<fcppt::either::no_error>(_error);
        }
      }());
}
}

#endif
