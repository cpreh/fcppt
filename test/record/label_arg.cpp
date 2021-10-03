//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label_arg.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace
{
FCPPT_RECORD_MAKE_LABEL_ARG(texture, unsigned);

}

FCPPT_CATCH_BEGIN

TEST_CASE("record arg label", "[record]")
{
  using record_type = fcppt::record::object<
      fcppt::record::element<texture<0>, std::string>,
      fcppt::record::element<texture<1>, std::string>>;

  record_type const test_sprite{
      texture<0>{} = std::string("ground"), texture<1>{} = std::string("clouds")};

  CHECK(fcppt::record::get<texture<0>>(test_sprite) == std::string("ground"));

  CHECK(fcppt::record::get<texture<1>>(test_sprite) == std::string("clouds"));
}

FCPPT_CATCH_END
