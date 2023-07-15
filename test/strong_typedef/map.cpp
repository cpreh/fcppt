//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/output_to_std_string.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_map.hpp>
#include <fcppt/strong_typedef_tag.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace
{
FCPPT_DECLARE_STRONG_TYPEDEF(int, strong_int);

using int_unique_ptr = fcppt::unique_ptr<int>;

FCPPT_DECLARE_STRONG_TYPEDEF(int_unique_ptr, strong_int_ptr);

using move_test = fcppt::catch_::movable<int_unique_ptr>;

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("strong_typedef_map", "[strongtypedef]")
{
  fcppt::strong_typedef<std::string, fcppt::strong_typedef_tag<strong_int>> const result{
      fcppt::strong_typedef_map(
          strong_int{5}, [](int const _value) { return fcppt::output_to_std_string(_value); })};

  CHECK(result.get() == "5");
}

TEST_CASE("strong_typedef_map move", "[strongtypedef]")
{
  fcppt::strong_typedef<move_test, fcppt::strong_typedef_tag<strong_int_ptr>> const result{
      fcppt::strong_typedef_map(
          strong_int_ptr{fcppt::make_unique_ptr<int>(5)},
          [](int_unique_ptr &&_ptr) { return move_test{std::move(_ptr)}; })};

  CHECK(*result.get().value() == 5);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
