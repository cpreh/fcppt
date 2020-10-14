//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/sequence_iteration.hpp>
#include <fcppt/algorithm/update_action.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm::sequence_iteration",
	"[algorithm]"
)
{
	using
	sequence
	=
	std::vector<
		int
	>;

	sequence seq{
		1,
		2,
		3,
		4
	};

	fcppt::algorithm::sequence_iteration(
		seq,
		[](
			int const _value
		)
		{
			return
				_value
				%
				2
				==
				0
				?
					fcppt::algorithm::update_action::keep
				:
					fcppt::algorithm::update_action::remove
				;
		}
	);

	CHECK(
		seq
		==
		sequence{
			2,
			4
		}
	);
}
