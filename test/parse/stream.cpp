//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_ref.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/use.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/column.hpp>
#include <fcppt/parse/line.hpp>
#include <fcppt/parse/location.hpp>
#include <fcppt/parse/parse.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/position_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/detail/stream_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <ios>
#include <istream>
#include <sstream>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::stream", "[parse]")
{
  std::istringstream string_stream{"xy\nz\n"};

  fcppt::parse::detail::stream<char> stream{
      fcppt::reference_to_base<std::istream>(fcppt::make_ref(string_stream))};

  auto const parse_one{
      [&stream] { FCPPT_USE(fcppt::parse::parse(fcppt::parse::char_{}, stream)); }};

  using position = fcppt::parse::position<char>;

  using offset = position::pos_type;

  CHECK(
      stream.get_position() == position{
                                   offset{},
                                   fcppt::optional::make(fcppt::parse::location{
                                       fcppt::parse::line{1U}, fcppt::parse::column{1U}})});

  parse_one();

  CHECK(
      stream.get_position() ==
      position{
          offset{} + std::streamoff{1},
          fcppt::optional::make(
              fcppt::parse::location{fcppt::parse::line{1U}, fcppt::parse::column{2U}})});

  parse_one();

  CHECK(
      stream.get_position() ==
      position{
          offset{} + std::streamoff{2},
          fcppt::optional::make(
              fcppt::parse::location{fcppt::parse::line{1U}, fcppt::parse::column{3U}})});

  parse_one();

  CHECK(
      stream.get_position() ==
      position{
          offset{} + std::streamoff{3},
          fcppt::optional::make(
              fcppt::parse::location{fcppt::parse::line{2U}, fcppt::parse::column{1U}})});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
