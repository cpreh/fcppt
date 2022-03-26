//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/strong_typedef_std_hash.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>

namespace
{
FCPPT_DECLARE_STRONG_TYPEDEF(int, strong_int);

}

FCPPT_CATCH_BEGIN

TEST_CASE("strong_typedef_hash", "[strongtypedef]")
{
  using hash_set = std::unordered_set<strong_int>;

  hash_set const elements{strong_int(1), strong_int(2)};

  CHECK(elements.contains(strong_int(1)));

  CHECK(elements.contains(strong_int(2)));

  CHECK_FALSE(elements.contains(strong_int(3)));
}

FCPPT_CATCH_END
