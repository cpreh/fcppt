//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/either/try_call.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <exception>
#include <stdexcept>
#include <string>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	either_try_call
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::either::object<
		std::string,
		int
	>
	either_int;

	auto const translate_exception(
		[](
			std::exception const &_error
		)
		{
			return
				std::string{
					_error.what()
				};
		}
	);


	BOOST_CHECK_EQUAL(
		fcppt::either::try_call<
			std::exception
		>(
			[]{
				return
					42;
			},
			translate_exception
		),
		either_int{
			42
		}
	);

	BOOST_CHECK(
		fcppt::either::try_call<
			std::exception
		>(
			[]()
			->
			int
			{
				throw
					std::runtime_error{
						"test"
					};
			},
			translate_exception
		).has_failure()
	);
}
