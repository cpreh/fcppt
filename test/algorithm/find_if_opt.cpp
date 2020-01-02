//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/find_if_opt.hpp>
#include <fcppt/catch/optional.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm find_if_opt"
	"[algorithm_find_if_opt]"
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

	CHECK(
		fcppt::algorithm::find_if_opt(
			vec,
			[](
				int const _i
			)
			{
				return
					_i == 3;
			}
		)
		==
		fcppt::optional::make(
			std::next(
				vec.begin(),
				2
			)
		)
	);

	CHECK(
		fcppt::algorithm::find_if_opt(
			vec,
			[](
				int const _i
			)
			{
				return
					_i == 4;
			}
		)
		==
		fcppt::optional::object<
			int_vector::const_iterator
		>{}
	);
}
