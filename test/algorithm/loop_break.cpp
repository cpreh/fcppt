//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/loop.hpp>
#include <fcppt/algorithm/loop_break.hpp>
#include <fcppt/algorithm/loop_break_tuple.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <tuple>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_loop_break_tuple
)
{
FCPPT_PP_POP_WARNING

	auto const tuple(
		std::make_tuple(
			42,
			10L
		)
	);

	std::string result;

	fcppt::algorithm::loop_break(
		tuple,
		[
			&result
		](
			auto const &_value
		)
		{
			result +=
				std::to_string(
					_value
				);

			return
				fcppt::loop::continue_;
		}
	);

	BOOST_CHECK_EQUAL(
		result,
		"4210"
	);
}
