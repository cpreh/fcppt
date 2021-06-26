//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/type_name_from_info.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/print.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <string>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>

TEST_CASE("mpl::list::print", "[mpl]")
{
  std::ostringstream out{};
  fcppt::mpl::list::print<fcppt::mpl::list::object<int, std::string>>(out);
  CHECK(
      out.str() == "(" + fcppt::type_name_from_info(typeid(int)) + "," +
                       fcppt::type_name_from_info(typeid(std::string)) + ")");
}
