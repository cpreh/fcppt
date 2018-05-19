//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/container/tuple/push_back.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <string>
#include <tuple>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::tuple::push_back",
	"[container],[tuple]"
)
{
	CHECK(
		fcppt::container::tuple::push_back(
			std::tuple<
				int,
				bool
			>{
				1,
				false
			},
			std::string{
				"test"
			}
		)
		==
		std::tuple<
			int,
			bool,
			std::string
		>{
			1,
			false,
			std::string{
				"test"
			}
		}
	);
}

TEST_CASE(
	"container::tuple::push_back move",
	"[container],[tuple]"
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	std::tuple<
		int_unique_ptr,
		int_unique_ptr
	> const result(
		fcppt::container::tuple::push_back(
			std::tuple<
				int_unique_ptr
			>{
				fcppt::make_unique_ptr<
					int
				>(
					1
				)
			},
			fcppt::make_unique_ptr<
				int
			>(
				2
			)
		)
	);

	CHECK(
		*std::get<
			0
		>(
			result
		)
		==
		1
	);

	CHECK(
		*std::get<
			1
		>(
			result
		)
		==
		2
	);
}
