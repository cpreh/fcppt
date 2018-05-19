//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/container/make_move_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container move_range",
	"[container]"
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	std::vector<
		int_unique_ptr
	>
	int_unique_ptr_vector;

	FCPPT_MAKE_STRONG_TYPEDEF(
		int_unique_ptr,
		strong_int_unique_ptr
	);

	typedef
	std::vector<
		strong_int_unique_ptr
	>
	strong_int_unique_ptr_vector;

	strong_int_unique_ptr_vector const result(
		fcppt::algorithm::map<
			strong_int_unique_ptr_vector
		>(
			fcppt::container::make_move_range(
				fcppt::assign::make_container<
					int_unique_ptr_vector
				>(
					fcppt::make_unique_ptr<
						int
					>(
						0
					),
					fcppt::make_unique_ptr<
						int
					>(
						1
					)
				)
			),
			[](
				int_unique_ptr &&_ptr
			)
			{
				return
					strong_int_unique_ptr(
						std::move(
							_ptr
						)
					);
			}
		)
	);

	REQUIRE(
		result.size()
		==
		2u
	);

	CHECK(
		*result[0].get()
		==
		0
	);

	CHECK(
		*result[1].get()
		==
		1
	);
}
