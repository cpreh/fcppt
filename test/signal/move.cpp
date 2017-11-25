//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	signal_move
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::signal::object<
		int_unique_ptr ()
	>
	signal_type;

	signal_type signal{
		signal_type::combiner_function{
			[](
				int_unique_ptr &&_ptr1,
				int_unique_ptr &&_ptr2
			)
			{
				return
					fcppt::make_unique_ptr<
						int
					>(
						*_ptr1
						+
						*_ptr2
					);
			}
		}
	};

	fcppt::signal::auto_connection const con1{
		signal.connect(
			signal_type::function{
				[]{
					return
						fcppt::make_unique_ptr<
							int
						>(
							1
						);
				}
			}
		)
	};

	fcppt::signal::auto_connection const con2{
		signal.connect(
			signal_type::function{
				[]{
					return
						fcppt::make_unique_ptr<
							int
						>(
							2
						);
				}
			}
		)
	};

	BOOST_CHECK_EQUAL(
		*signal(
			signal_type::initial_value{
				fcppt::make_unique_ptr<
					int
				>(
					0
				)
			}
		),
		3
	);
}
