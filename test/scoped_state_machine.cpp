//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/scoped_state_machine.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
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
	FCPPT_NONCOPYABLE(
		machine
	);
public:
	machine()
	{
	}

	~machine()
	override
	{
	}
};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4265)

class state
:
	public boost::statechart::simple_state<
		state,
		machine
	>
{
	FCPPT_NONCOPYABLE(
		state
	);
public:
	state()
	{
	}

	~state()
	{
	}
};

FCPPT_PP_POP_WARNING

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	scoped_state_machine
)
{
FCPPT_PP_POP_WARNING

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
