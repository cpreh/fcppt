//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/to_uint_ptr.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("cast::to_uint_ptr"
          "[cast]")
{
  int const value1{1};

  int const value2{2};

  std::uintptr_t const ptr1{fcppt::cast::to_uint_ptr(&value1)};

  std::uintptr_t const ptr2{fcppt::cast::to_uint_ptr(&value2)};

  CHECK(ptr1 != ptr2);
}

FCPPT_CATCH_END
