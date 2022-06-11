//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/record.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/catch/variant.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/base_unique_ptr.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_base.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("options::base"
          "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(arg_label);

  using result_type = fcppt::record::object<fcppt::record::element<arg_label, int>>;

  fcppt::options::base_unique_ptr<result_type> const base{
      fcppt::options::make_base<result_type>(fcppt::options::argument<arg_label, int>{
          fcppt::options::long_name{FCPPT_TEXT("arg")}, fcppt::options::optional_help_text{}})};

  CHECK(
      fcppt::options::parse(*base, fcppt::args_vector{FCPPT_TEXT("123")}) ==
      fcppt::options::make_success(result_type{arg_label{} = 123}));

  CHECK(fcppt::options::parse(*base, fcppt::args_vector{FCPPT_TEXT("test")}).has_failure());

  CHECK(fcppt::options::parse(*base, fcppt::args_vector{}).has_failure());
}

FCPPT_CATCH_END
