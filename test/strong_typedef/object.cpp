//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef_impl.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("strong_typedef object", "[strongtypedef]")
{
	FCPPT_DECLARE_STRONG_TYPEDEF(int, strong_int);

	constexpr strong_int const v{1};
	CHECK(v.get() == 1);
	static_assert(v.get() == 1);
}

TEST_CASE("strong_typedef move", "[strongtypedef]")
{
  using int_unique_ptr = fcppt::unique_ptr<int>;

  FCPPT_DECLARE_STRONG_TYPEDEF(int_unique_ptr, strong_int_ptr);

  strong_int_ptr val(fcppt::make_unique_ptr<int>(1));

  strong_int_ptr val2(std::move(val));

  CHECK(*val2.get() == 1);

  strong_int_ptr val3(fcppt::make_unique_ptr<int>(2));

  val3 = std::move(val2);

  CHECK(*val3.get() == 1);
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
