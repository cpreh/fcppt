//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/vector.hpp>
#include <fcppt/algorithm/shift_compare.hpp>
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

BOOST_AUTO_TEST_CASE(shift_compare)
{
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
