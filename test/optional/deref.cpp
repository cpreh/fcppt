//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_comparison.hpp> // IWYU pragma: keep
#include <fcppt/reference_output.hpp> // IWYU pragma: keep
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/deref.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp> // IWYU pragma: keep
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("optional::deref unique_ptr", "[optional]")
{
  using int_unique_ptr = fcppt::unique_ptr<int>;

  using optional_int_unique_ptr = fcppt::optional::object<int_unique_ptr>;

  optional_int_unique_ptr const opt_ptr(fcppt::make_unique_ptr<int>(42));

  CHECK(
      fcppt::optional::deref(opt_ptr) ==
      fcppt::optional::reference<int>(fcppt::make_ref(*opt_ptr.get_unsafe())));
}

TEST_CASE("optional::deref vector", "[optional]")
{
  using int_vector = std::vector<int>;

  int_vector ints{1, 2, 3};

  CHECK(
      fcppt::optional::deref(fcppt::optional::object<int_vector::iterator>(ints.begin())) ==
      fcppt::optional::reference<int>(fcppt::make_ref(ints.front())));

  int const &const_front(ints.front());

  CHECK(
      fcppt::optional::deref(fcppt::optional::object<int_vector::const_iterator>(ints.cbegin())) ==
      fcppt::optional::reference<int const>(fcppt::make_cref(const_front)));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
