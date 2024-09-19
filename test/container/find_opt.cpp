//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/reference_comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/reference_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/strong_typedef.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/find_opt.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/optional/reference.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <set>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::find_opt", "[container]")
{
  FCPPT_DECLARE_STRONG_TYPEDEF(int, strong_int);

  struct comp
  {
    bool operator()(int const _left, int const _right) const { return _left < _right; }

    bool operator()(int const _value, strong_int const _comp) const { return _value < _comp.get(); }

    bool operator()(strong_int const _comp, int const _value) const { return _comp.get() < _value; }

    FCPPT_PP_PUSH_WARNING
    FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-local-typedefs)
    using is_transparent = void;
    FCPPT_PP_POP_WARNING
  };

  using int_set = std::set<int, comp>;

  int_set const set{1, 2, 3};

  using optional_int_ref = fcppt::optional::reference<int const>;

  CHECK(
      fcppt::container::find_opt(set, strong_int(3)) ==
      optional_int_ref(fcppt::make_cref(*set.find(3))));

  CHECK(fcppt::container::find_opt(set, strong_int(4)) == optional_int_ref{});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
