//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/ptr_container_erase.hpp>
#include <fcppt/container/ptr/push_back_unique_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>

BOOST_AUTO_TEST_CASE(
	ptr_container_erase
)
{
	typedef boost::ptr_vector<
		int
	> int_vector;

	int_vector test;

	fcppt::container::ptr::push_back_unique_ptr(
		test,
		fcppt::make_unique_ptr<
			int
		>(
			1
		)
	);

	fcppt::container::ptr::push_back_unique_ptr(
		test,
		fcppt::make_unique_ptr<
			int
		>(
			2
		)
	);

	BOOST_REQUIRE(
		test.size() == 2u
	);

	fcppt::algorithm::ptr_container_erase(
		test,
		&test[0]
	);

	BOOST_REQUIRE(
		test.size() == 1u
	);

	BOOST_CHECK(
		test[0] == 2
	);

	fcppt::algorithm::ptr_container_erase(
		test,
		static_cast<
			int const *
		>(
			&test[0]
		)
	);

	BOOST_REQUIRE(
		test.empty()
	);
}
