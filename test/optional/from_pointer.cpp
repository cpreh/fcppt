//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/from_pointer.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

void
test_function(
	int
)
{
}

}

BOOST_AUTO_TEST_CASE(
	optional_from_pointer
)
{
	typedef
	void (*fun_ptr)(int);

	BOOST_CHECK(
		fcppt::optional::from_pointer(
			&test_function
		).has_value()
	);

	fun_ptr const ptr(
		nullptr
	);

	BOOST_CHECK(
		!fcppt::optional::from_pointer(
			ptr
		).has_value()
	);
}
