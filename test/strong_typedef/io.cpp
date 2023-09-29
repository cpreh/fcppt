//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_impl.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/strong_typedef_input.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/io/extract.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/preprocessor/disable_gnu_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>

namespace
{
FCPPT_DECLARE_STRONG_TYPEDEF(int, strong_int);

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("strong_typedef output", "[strongtypedef]")
{
  std::stringstream stream{};

  strong_int const test(1);

  stream << test;

  strong_int result(0);

  REQUIRE(stream >> result);

  CHECK(test == result);
}

TEST_CASE("strong_typedef input", "[strongtypedef]")
{
  std::stringstream stream{};

  stream << 1;

  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GNU_GCC_WARNING(-Wmaybe-uninitialized)

  fcppt::optional::object<strong_int> const result2{fcppt::io::extract<strong_int>(stream)};

  FCPPT_PP_POP_WARNING

  CHECK(fcppt::optional::make(strong_int{1}) == result2);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
