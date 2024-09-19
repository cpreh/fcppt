//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/record/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("record comparison", "[record]")
{
  FCPPT_RECORD_MAKE_LABEL(int_label);

  FCPPT_RECORD_MAKE_LABEL(bool_label);

  using int_element = fcppt::record::element<int_label, int>;

  using bool_element = fcppt::record::element<bool_label, bool>;

  using record1 = fcppt::record::object<int_element, bool_element>;

  using record2 = fcppt::record::object<bool_element, int_element>;

  CHECK(
      record1(int_label{} = 42, bool_label{} = false) ==
      record2(int_label{} = 42, bool_label{} = false));

  CHECK(
      record1(int_label{} = 42, bool_label{} = false) ==
      record1(int_label{} = 42, bool_label{} = false));

  CHECK(
      record1(int_label{} = 42, bool_label{} = false) !=
      record1(int_label{} = 42, bool_label{} = true));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
