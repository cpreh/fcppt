//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/algorithm/map_optional.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm map_optional",
	"[algorithm_map_optional]",
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

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

	int_unique_ptr_vector const result(
		fcppt::algorithm::map_optional<
			int_unique_ptr_vector
		>(
			int_vector{
				1,
				2,
				3
			},
			[](
				int const _value
			)
			{
				typedef
				fcppt::optional::object<
					int_unique_ptr
				>
				optional_ptr;

				return
					_value
					==
					1
					?
						optional_ptr(
							fcppt::make_unique_ptr<
								int
							>(
								_value
							)
						)
					:
						optional_ptr()
					;
			}
		)
	);

	REQUIRE(
		result.size()
		==
		1u
	);

	CHECK(
		*result[0]
		==
		1
	);
}
