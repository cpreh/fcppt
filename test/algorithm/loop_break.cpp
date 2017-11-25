//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/loop.hpp>
#include <fcppt/algorithm/loop_break.hpp>
#include <fcppt/algorithm/loop_break_tuple.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <tuple>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	algorithm_loop_break_tuple
)
{
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
