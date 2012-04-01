//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(math_matrix_view)
{
FCPPT_PP_POP_WARNING

	typedef int value_type;

	std::size_t const size = 3;

	typedef
	fcppt::math::matrix::static_<
		value_type,
		size,
		size
	>::type
	matrix_type;

	typedef
	fcppt::math::vector::static_<
		value_type,
		size
	>::type
	vector_type;

	matrix_type const t(
		-3, 2, -5,
		-1, 0, -2,
		3, -4, 1
	);

	BOOST_CHECK(
		t[0]
		== vector_type(
			-3,
			2,
			-5
		)
	);
}
