//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/enum/from_int_exn.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class testenum
{
	enum1,
	enum2,
	fcppt_maximum = enum2
};

}

BOOST_AUTO_TEST_CASE(
	enum_from_int
)
{
	BOOST_CHECK(
		fcppt::enum_::from_int_exn<
			testenum
		>(
			1u
		)
		==
		testenum::enum2
	);

	BOOST_CHECK_THROW(
		fcppt::enum_::from_int_exn<
			testenum
		>(
			2u
		),
		fcppt::exception
	);
}
