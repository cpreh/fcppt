//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/type_name_from_info.hpp>
#include <fcppt/metal/sequence_to_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>

TEST_CASE("metal::print", "[metal]")
{
  CHECK(
      fcppt::metal::sequence_to_string<::metal::list<int, std::string>>() ==
      "(" + fcppt::type_name_from_info(typeid(int)) + "," +
          fcppt::type_name_from_info(typeid(std::string)) + ")");
}
