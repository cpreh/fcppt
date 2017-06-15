//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

bool
check_exception(
	fcppt::exception const &_exn
)
{
	return
		_exn.string()
		==
		FCPPT_TEXT("Invalid");
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_to_exception
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	auto const make_exception(
		[]{
			return
				fcppt::exception(
					FCPPT_TEXT("Invalid")
				);
		}
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional::to_exception(
			optional_int(
				3
			),
			make_exception
		),
		3
	);

	BOOST_CHECK_EXCEPTION(
		fcppt::optional::to_exception(
			optional_int(),
			make_exception
		),
		fcppt::exception,
		check_exception
	);
}
