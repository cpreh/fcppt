//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/function.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


template
class
fcppt::function<
	int (
		int
	)
>;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	function
)
{

FCPPT_PP_POP_WARNING


	typedef
	fcppt::function<
		int (
			int
		)
	>
	function_type;

	function_type const fun{
		[](
			int const _val
		)
		{
			return
				_val
				+
				10;
		}
	};

	BOOST_CHECK_EQUAL(
		fun(
			10
		),
		20
	);
}


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	function_move
)
{

FCPPT_PP_POP_WARNING

	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::function<
		int (
			int_unique_ptr &&
		)
	>
	function_type;

	function_type const fun{
		[](
			int_unique_ptr &&_val
		)
		{
			return
				*_val
				+
				10;
		}
	};

	BOOST_CHECK_EQUAL(
		fun(
			fcppt::make_unique_ptr<
				int
			>(
				10
			)
		),
		20
	);
}
