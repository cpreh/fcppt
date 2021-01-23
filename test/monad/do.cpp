//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/monad/do.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/monad.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace
{
template <typename F, typename T1, typename T2>
auto lift_a2(F const &_f, T1 const &_t1, T2 const &_t2)
{
  return fcppt::monad::do_(
      _t1,
      [&_t2](auto const &) { return _t2; },
      [&_f](auto const &_v1, auto const &_v2) { return _f(_v1, _v2); });
}
}

TEST_CASE("monad::do", "[monad]")
{
  CHECK(
      lift_a2(
          [](int const _i, std::string const &_s) {
            return fcppt::optional::make(_i == 10 && _s == "x");
          },
          fcppt::optional::make(10),
          fcppt::optional::make(std::string{"x"})) == fcppt::optional::make(true));
}
