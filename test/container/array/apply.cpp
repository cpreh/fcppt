//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/container/array/apply.hpp>
#include <fcppt/container/array/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <utility>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	array_apply
)
{
	typedef
	std::array<
		std::pair<
			int,
			bool
		>,
		2
	>
	result_array;

	result_array const result(
		fcppt::container::array::apply(
			[](
				int const _value1,
				bool const _value2
			)
			{
				return
					std::make_pair(
						_value1,
						_value2
					);
			},
			fcppt::container::array::make(
				1,
				2
			),
			fcppt::container::array::make(
				true,
				false
			)
		)
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0
		>(
			result
		).first,
		1
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0
		>(
			result
		).second,
		true
	);

	BOOST_CHECK_EQUAL(
		std::get<
			1
		>(
			result
		).first,
		2
	);

	BOOST_CHECK_EQUAL(
		std::get<
			1
		>(
			result
		).second,
		false
	);
}

BOOST_AUTO_TEST_CASE(
	array_apply_move
)
{
	typedef
	std::array<
		std::pair<
			fcppt::unique_ptr<
				int
			>,
			fcppt::unique_ptr<
				int
			>
		>,
		1
	>
	result_array;

	result_array const result(
		fcppt::container::array::apply(
			[](
				fcppt::unique_ptr<
					int
				> &&_arg1,
				fcppt::unique_ptr<
					int
				> &&_arg2
			)
			{
				return
					std::make_pair(
						std::move(
							_arg1
						),
						std::move(
							_arg2
						)
					);
			},
			fcppt::container::array::make(
				fcppt::make_unique_ptr<
					int
				>(
					1
				)
			),
			fcppt::container::array::make(
				fcppt::make_unique_ptr<
					int
				>(
					2
				)
			)
		)
	);

	BOOST_CHECK_EQUAL(
		*std::get<
			0
		>(
			result
		).first,
		1
	);

	BOOST_CHECK_EQUAL(
		*std::get<
			0
		>(
			result
		).second,
		2
	);
}

BOOST_AUTO_TEST_CASE(
	array_apply_empty
)
{
	std::array<
		fcppt::unit,
		0
	> const result(
		fcppt::container::array::apply(
			[](
				bool,
				int
			)
			{
				return
					fcppt::unit{};
			},
			std::array<
				bool,
				0
			>{},
			std::array<
				int,
				0
			>{}
		)
	);

	BOOST_CHECK(
		result.empty()
	);
}
