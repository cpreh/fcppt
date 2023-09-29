//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/type_name_from_info.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <string>
#include <typeinfo> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("mpl::list::output", "[mpl]")
{
  std::ostringstream out{};
  out << fcppt::mpl::list::object<int, std::string>{};
  CHECK(
      out.str() == "(" + fcppt::type_name_from_info(typeid(int)) + "," +
                       fcppt::type_name_from_info(typeid(std::string)) + ")");
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
