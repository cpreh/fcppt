//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/algorithm/array_init_const.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	array_init_const
)
{
	typedef
	std::array<
		int,
		2
	>
	array;

	array const inited(
		fcppt::algorithm::array_init_const<
			array
		>(
			42
		)
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0
		>(
			inited
		),
		42
	);

	BOOST_CHECK_EQUAL(
		std::get<
			1
		>(
			inited
		),
		42
	);
}
