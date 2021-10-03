//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/bitfield/object.hpp>
#include <fcppt/container/bitfield/std_hash.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::bitfield hash", "[container],[bitfield]")
{
  enum class test_enum
  {
    test1,
    test2,
    fcppt_maximum = test2
  };

  using bitfield = fcppt::container::bitfield::object<test_enum>;

  using bitfield_set = std::unordered_set<bitfield>;

  bitfield_set const values{
      bitfield{test_enum::test1}, bitfield{test_enum::test1, test_enum::test2}};

  CHECK(values.count(bitfield{test_enum::test1, test_enum::test2}) == 1U);

  CHECK(values.count(bitfield{test_enum::test1}) == 1U);

  CHECK(values.count(bitfield{test_enum::test2}) == 0U);
}

FCPPT_CATCH_END
