//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/unregister/base.hpp>
#include <fcppt/signal/unregister/function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <functional>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::signal::object<
	void (),
	fcppt::signal::unregister::base
>
signal_type;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	signals_unregister
)
{
FCPPT_PP_POP_WARNING

	std::vector<
		int
	> values;

	signal_type::function const empty_function{
		[]{}
	};

	auto const unregister(
		[
			&values
		](
			int const _value
		)
		{
			values.push_back(
				_value
			);
		}
	);

	signal_type sig;

	{
		fcppt::signal::auto_connection const con1(
			sig.connect(
				empty_function,
				fcppt::signal::unregister::function{
					std::bind(
						unregister,
						42
					)
				}
			)
		);
	}

	BOOST_CHECK_EQUAL(
		values.size(),
		1u
	);

	BOOST_CHECK_EQUAL(
		values.back(),
		42
	);

	{
		fcppt::signal::auto_connection const con2(
			sig.connect(
				empty_function,
				fcppt::signal::unregister::function{
					std::bind(
						unregister,
						100
					)
				}
			)
		);
	}

	BOOST_CHECK_EQUAL(
		values.size(),
		2u
	);

	BOOST_CHECK_EQUAL(
		values.back(),
		100
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	signal_simple_move
)
{
FCPPT_PP_POP_WARNING

	signal_type sig;

	bool done{
		false
	};

	bool unregistered{
		false
	};

	{
		fcppt::signal::auto_connection const con1(
			sig.connect(
				signal_type::function{
					[
						&done
					]{
						done = true;
					}
				},
				fcppt::signal::unregister::function{
					[
						&unregistered
					]
					{
						unregistered = true;
					}
				}
			)
		);

		signal_type sig2(
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

	BOOST_CHECK(
		unregistered
	);
}
