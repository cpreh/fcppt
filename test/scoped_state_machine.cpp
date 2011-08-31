//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/scoped_state_machine.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{

class state;

class machine
:
	public boost::statechart::state_machine<
		machine,
		state
	>
{
};

class state
:
	public boost::statechart::simple_state<
		state,
		machine
	>
{
};

}

BOOST_AUTO_TEST_CASE(
	scoped_state_machine
)
{
	machine test;

	BOOST_REQUIRE(
		test.terminated()
	);

	{
		typedef fcppt::scoped_state_machine<
			machine
		> scoped_machine;

		scoped_machine const scoped(
			test
		);

		BOOST_REQUIRE(
			!test.terminated()
		);
	}

	BOOST_REQUIRE(
		test.terminated()
	);
}
