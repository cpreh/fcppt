//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/find_by_opt.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm find_by_opt",
	"[algorithm_find_by_opt]",
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const vec{
		1,
		2,
		3
	};

	typedef
	fcppt::optional::object<
		std::string
	>
	result_type;

	CHECK(
		fcppt::algorithm::find_by_opt(
			vec,
			[](
				int const _i
			)
			->
			result_type
			{
				return
					(_i % 2 == 0)
					?
						result_type(
							std::string(
								"test"
							)
						)
					:
						result_type()
					;
			}
		)
		==
		result_type(
			std::string(
				"test"
			)
		)
	);

	CHECK_FALSE(
		fcppt::algorithm::find_by_opt(
			vec,
			[](
				int const _i
			)
			->
			result_type
			{
				return
					_i == 4
					?
						result_type(
							std::string(
								"test"
							)
						)
					:
						result_type()
					;

			}
		).has_value()
	);
}
