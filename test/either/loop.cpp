//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/pop_back.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/loop.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::loop",
	"[either]"
)
{
	CHECK(
		fcppt::either::loop(
			[]{
				return
					fcppt::either::make_failure<
						int
					>(
						std::string{
							"test"
						}
					);
			},
			[](
				int
			)
			{
			}
		)
		==
		std::string{
			"test"
		}
	);

	{
		std::vector<
			int
		> ints{
			1, 2, 3
		};

		int result{
			0
		};

		CHECK(
			fcppt::either::loop(
				[
					&ints
				]{
					return
						fcppt::either::from_optional(
							fcppt::container::pop_back(
								ints
							),
							[]{
								return
									std::string{
										"failure"
									};
							}
						);
				},
				[
					&result
				](
					int const _value
				)
				{
					result +=
						_value;
				}
			)
			==
			std::string{
				"failure"
			}
		);

		CHECK(
			result
			==
			6
		);
	}
}
