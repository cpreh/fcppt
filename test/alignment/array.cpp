//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/alignment/array.hpp>
#include <fcppt/alignment/is_aligned.hpp>
#include <fcppt/alignment/size_type.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	alignment_array
)
{
FCPPT_PP_POP_WARNING

	fcppt::alignment::size_type const alignment = sizeof(long) * 2;

	typedef fcppt::alignment::array<
		unsigned char,
		3,
		alignment
	>::type array_type;

	typedef std::vector<
		array_type
	> array_vector;

	array_vector arrays;

	arrays.push_back(
		array_type()
	);
	
	arrays.push_back(
		array_type()
	);
	
	BOOST_CHECK(
		fcppt::alignment::is_aligned(
			&arrays[0],
			alignment
		)
	);

	BOOST_CHECK(
		fcppt::alignment::is_aligned(
			&arrays[1],
			alignment
		)
	);
}
