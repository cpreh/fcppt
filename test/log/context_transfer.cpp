//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/clog.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_object.hpp>
#include <fcppt/log/print_locations.hpp>
#include <fcppt/log/parameters/with_context.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	log_context_transfer
)
{
FCPPT_PP_POP_WARNING

	fcppt::log::context context1;

	fcppt::log::location const head_location(
		FCPPT_TEXT("head")
	);

	fcppt::log::location const child_location(
		head_location
		/
		FCPPT_TEXT("child")
	);

	fcppt::log::context context2;

	fcppt::log::object object1(
		fcppt::log::parameters::with_context(
			context1,
			head_location
		)
	);

	fcppt::log::object object2(
		fcppt::log::parameters::with_context(
			context1,
			child_location
		)
	);

	fcppt::io::clog()
		<< FCPPT_TEXT("context1:\n");

	fcppt::log::print_locations(
		fcppt::io::clog(),
		context1,
		head_location
	);

	context1.transfer_to(
		context2
	);

	fcppt::io::clog()
		<< FCPPT_TEXT("\n\ncontext2:\n");

	fcppt::log::print_locations(
		fcppt::io::clog(),
		context2,
		head_location
	);

	BOOST_CHECK(
		context2.find(
			head_location
		).has_value()
	);

	BOOST_CHECK(
		context2.find(
			child_location
		).has_value()
	);
}
