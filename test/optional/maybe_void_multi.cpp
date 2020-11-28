//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/optional/maybe_void_multi.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("optional::maybe_void_multi", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  using optional_unsigned = fcppt::optional::object<unsigned>;

  int result{0};

  fcppt::optional::maybe_void_multi(
      [&result](int const _val1, unsigned const _val2) {
        result = _val1 + fcppt::cast::to_signed(_val2);
      },
      optional_int(10),
      optional_unsigned(20));

  CHECK(result == 30);
}
