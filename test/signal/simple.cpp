//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/signal/base.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/tr1/functional.hpp>
#include <boost/test/unit_test.hpp>

namespace
{

int global = 0;

void
add(
	int const _value 
)
{
	global += _value;
}

}

BOOST_AUTO_TEST_CASE(
	signal_simple
)
{
	typedef fcppt::signal::object<
		void ()
	> signal;

	signal sig;

	{
		fcppt::signal::scoped_connection const con1(
			sig.connect(
				std::tr1::bind(
					add,
					1
				)
			)
		);

		BOOST_REQUIRE(
			global == 0
		);
	
		sig();

		BOOST_REQUIRE(
			global == 1
		);

		fcppt::signal::scoped_connection const con2(
			sig.connect(
				std::tr1::bind(
					add,
					2
				)
			)
		);

		sig();

		BOOST_REQUIRE(
			global == 4
		);
	}

	sig();

	BOOST_REQUIRE(
		global == 4
	);

}
