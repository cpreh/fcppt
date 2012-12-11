//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/contains.hpp>
#include <fcppt/math/box/corner_points.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(test_corner_points)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::box::object
	<
		int,
		2
	>
	box_type;

	box_type box(
		box_type::vector(10,12),
		box_type::dim(24,26));

	std::cout << "Checking border points of box: " << box << '\n';

	typedef std::array<box_type::vector,4> vertex_array;

	vertex_array const vertices(
		fcppt::math::box::corner_points(
			box));

	std::cout << "Result: \n";

	for(
		vertex_array::const_iterator it(
			vertices.begin()
		);
		it != vertices.end();
		++it
	)
		std::cout << *it << '\n';

	std::cout << "Running checks now...\n";

	BOOST_CHECK(
		fcppt::algorithm::contains(
			vertices.begin(),
			vertices.end(),
			box_type::vector(10,12)));

	BOOST_CHECK(
		fcppt::algorithm::contains(
			vertices.begin(),
			vertices.end(),
			box_type::vector(34,12)));

	BOOST_CHECK(
		fcppt::algorithm::contains(
			vertices.begin(),
			vertices.end(),
			box_type::vector(10,38)));

	BOOST_CHECK(
		fcppt::algorithm::contains(
			vertices.begin(),
			vertices.end(),
			box_type::vector(34,38)));
}
