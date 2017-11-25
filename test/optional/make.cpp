//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	optional_make
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	optional_int const result(
		fcppt::optional::make(
			42
		)
	);

	BOOST_CHECK_EQUAL(
		result,
		optional_int{
			42
		}
	);
}
