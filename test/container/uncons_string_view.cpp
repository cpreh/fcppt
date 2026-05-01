//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/uncons_string_view.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <string_view>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::uncons_string_view", "[container]")
{
  {
    std::string empty{};

    CHECK_FALSE(fcppt::container::uncons_string_view(std::string_view{empty}).has_value());
  }

  {
    std::string const str{"ab"};

    fcppt::optional::maybe(
        fcppt::container::uncons_string_view(std::string_view{str}),
        [] { CHECK(false); },
        [](fcppt::tuple::object<char, std::string_view> const _value1)
        {
          CHECK(fcppt::tuple::get<0U>(_value1) == 'a');
          fcppt::optional::maybe(
              fcppt::container::uncons_string_view(fcppt::tuple::get<1U>(_value1)),
              [] { CHECK(false); },
              [](fcppt::tuple::object<char, std::string_view> const _value2)
              {
                CHECK(fcppt::tuple::get<0U>(_value2) == 'b');
                CHECK_FALSE(
                    fcppt::container::uncons_string_view(fcppt::tuple::get<1U>(_value2))
                        .has_value());
              });
        });
  }
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
