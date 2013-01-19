//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/shift_compare.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace
{
typedef
fcppt::math::vector::static_<int,3>::type
vector;
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	shift_compare
)
{
FCPPT_PP_POP_WARNING

	vector const first(1,2,3),second(3,1,2),third(3,2,1);

	BOOST_CHECK(
		fcppt::algorithm::shift_compare(
			first,
			second,
			std::equal_to<int>()) &&
		!fcppt::algorithm::shift_compare(
			first,
			third,
			std::equal_to<int>()));
}
