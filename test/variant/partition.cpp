//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/tuple.hpp>
#include <fcppt/tuple/comparison.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/partition.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("variany::partition", "[variant]")
{
  using variant = fcppt::variant::object<int,bool>;

  CHECK(
      fcppt::variant::partition(std::vector<variant>{variant{4}, variant{false}, variant{10}}) ==
      fcppt::tuple::make(std::vector<int>{4, 10}, std::vector<bool>{false}));
}

FCPPT_CATCH_END
