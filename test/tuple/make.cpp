//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/tuple.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/tuple/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("tuple::make", "[tuple]")
{
  CHECK(
  fcppt::tuple::make(4,std::string{"test"})
  ==
  fcppt::tuple::object<int,std::string>{4,std::string{"test"}});
}

FCPPT_CATCH_END
