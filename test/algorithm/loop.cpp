//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_int_range_count.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_metal.hpp>
#include <fcppt/metal/interval.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm_loop mpl"
	"[algorithm_loop]"
)
{
	int value{
		0
	};

	fcppt::algorithm::loop(
		fcppt::metal::interval<
			int,
			0,
			5
		>{},
		[
			&value
		](
			auto const _index
		)
		{
			FCPPT_USE(
				_index
			);

			typedef
			fcppt::tag_type<
				decltype(
					_index
				)
			>
			index;

			static_assert(
				index::value
				<
				5,
				""
			);

			value +=
				index::value;
		}
	);

	CHECK(
		value
		==
		10
	);
}

TEST_CASE(
	"algorithm_loop_range",
	"[algorithm_loop]"
)
{
	int value{
		0
	};

	fcppt::algorithm::loop(
		fcppt::make_int_range_count(
			5
		),
		[
			&value
		](
			int const _value
		)
		{
			value +=
				_value;
		}
	);

	CHECK(
		value
		==
		10
	);
}
