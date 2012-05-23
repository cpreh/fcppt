//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/function/detail/has_addressof_overload.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{

struct test_struct_no
{
};

struct test_struct_yes1
{
	int operator&()
	{
		return 42;
	}
};

struct test_struct_yes2
{
	int operator&() const
	{
		return 42;
	}
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	function_has_addressof_overload
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		!fcppt::function::detail::has_addressof_overload<
			void(*)()
		>::value
	);


	BOOST_CHECK(
		!fcppt::function::detail::has_addressof_overload<
			test_struct_no
		>::value
	);

	BOOST_CHECK(
		fcppt::function::detail::has_addressof_overload<
			test_struct_yes1
		>::value
	);

	BOOST_CHECK(
		fcppt::function::detail::has_addressof_overload<
			test_struct_yes2
		>::value
	);

	test_struct_yes1 test1;

	static_cast<
		void
	>(
		&test1
	);

	test_struct_yes2 test2;

	static_cast<
		void
	>(
		&test2
	);
}
