//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/contains_if.hpp>
#include <fcppt/algorithm/loop_break_tuple.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm::contains_if tuple",
	"[algorithm]"
)
{
	CHECK(
		fcppt::algorithm::contains_if(
			std::make_tuple(
				fcppt::optional::make(
					42
				),
				fcppt::optional::object<
					bool
				>{}
			),
			[](
				auto const &_opt
			)
			{
				return
					_opt.has_value();
			}
		)
	);

	CHECK_FALSE(
		fcppt::algorithm::contains_if(
			std::make_tuple(
				fcppt::optional::object<
					bool
				>{}
			),
			[](
				auto const &_opt
			)
			{
				return
					_opt.has_value();
			}
		)
	);
}
