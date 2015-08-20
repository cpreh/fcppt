//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/index_of_enum_array.hpp>
#include <fcppt/container/enum_array.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class test_enum
{
	test1,
	test2,
	fcppt_maximum = test2
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_find_opt
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::enum_array<
		test_enum,
		unsigned
	>
	array;

	array const test{{{
		1u,
		2u
	}}};

	BOOST_CHECK(
		fcppt::algorithm::index_of_enum_array(
			test,
			2u
		).get_unsafe()
		==
		test_enum::test2
	);

	BOOST_CHECK(
		!fcppt::algorithm::index_of_enum_array(
			test,
			3u
		).has_value()
	);
}
