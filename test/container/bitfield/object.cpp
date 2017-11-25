//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/bitfield/enum_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class test_enum
{
	test1,
	test2,
	test3,
	fcppt_maximum = test3
};

typedef
fcppt::container::bitfield::enum_object<
	test_enum
>
bitfield;

}

BOOST_AUTO_TEST_CASE(
	container_bitfield_initializer_list
)
{
	bitfield const field1{
		test_enum::test1,
		test_enum::test3
	};

	BOOST_CHECK(
		field1.get(
			test_enum::test1
		)
	);

	BOOST_CHECK(
		!field1.get(
			test_enum::test2
		)
	);

	BOOST_CHECK(
		field1.get(
			test_enum::test3
		)
	);
}
