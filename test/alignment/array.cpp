//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/alignment/array.hpp>
#include <fcppt/alignment/is_aligned.hpp>
#include <fcppt/alignment/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>

BOOST_AUTO_TEST_CASE(
	alignment_array
)
{
	fcppt::alignment::size_type const alignment = sizeof(long) * 2;

	typedef fcppt::alignment::array<
		unsigned char,
		3,
		alignment
	>::type array_type;

	array_type array1;
	array_type array2;
	array_type array3;

	BOOST_CHECK(
		fcppt::alignment::is_aligned(
			&array1,
			alignment
		)
	);

	BOOST_CHECK(
		fcppt::alignment::is_aligned(
			&array2,
			alignment
		)
	);

	BOOST_CHECK(
		fcppt::alignment::is_aligned(
			&array3,
			alignment
		)
	);
}
