//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/signal/base.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <functional>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::signal::object<
	void ()
>
signal;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	signal_simple
)
{
FCPPT_PP_POP_WARNING

	int counter{
		0
	};

	auto const add(
		[
			&counter
		](
			int const _value
		)
		{
			counter += _value;
		}
	);

	signal sig;

	{
		fcppt::signal::auto_connection const con1(
			sig.connect(
				signal::function{
					std::bind(
						add,
						1
					)
				}
			)
		);

		BOOST_REQUIRE(
			counter == 0
		);

		sig();

		BOOST_REQUIRE(
			counter == 1
		);

		fcppt::signal::auto_connection const con2(
			sig.connect(
				signal::function{
					std::bind(
						add,
						2
					)
				}
			)
		);

		sig();

		BOOST_REQUIRE(
			counter == 4
		);
	}

	sig();

	BOOST_REQUIRE(
		counter == 4
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	signal_simple_move
)
{
FCPPT_PP_POP_WARNING

	signal sig;

	bool done{
		false
	};

	fcppt::signal::auto_connection const con1(
		sig.connect(
			signal::function{
				[
					&done
				]{
					done = true;
				}
			}
		)
	);

	signal sig2(
		std::move(
			sig
		)
	);

	BOOST_CHECK(
		sig.empty()
	);

	sig2();

	BOOST_CHECK(
		done
	);
}
