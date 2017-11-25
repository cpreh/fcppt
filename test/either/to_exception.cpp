//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

bool
check_exception(
	fcppt::exception const &_exn
)
{
	return
		_exn.string()
		==
		FCPPT_TEXT("Invalid");
}

}

BOOST_AUTO_TEST_CASE(
	either_to_exception
)
{
	typedef
	fcppt::either::object<
		fcppt::string,
		int
	>
	either_int;

	auto const make_exception(
		[](
			fcppt::string const &_error
		){
			return
				fcppt::exception(
					_error
				);
		}
	);

	BOOST_CHECK_EQUAL(
		fcppt::either::to_exception(
			either_int{
				3
			},
			make_exception
		),
		3
	);

	BOOST_CHECK_EXCEPTION(
		fcppt::either::to_exception(
			either_int{
				fcppt::string(
					FCPPT_TEXT("Invalid")
				)
			},
			make_exception
		),
		fcppt::exception,
		check_exception
	);
}
