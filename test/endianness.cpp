//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/endianness/from_big_endian.hpp>
#include <fcppt/endianness/from_little_endian.hpp>
#include <fcppt/endianness/host_format.hpp>
#include <fcppt/endianness/is_big_endian.hpp>
#include <fcppt/endianness/is_little_endian.hpp>
#include <fcppt/endianness/swap.hpp>
#include <fcppt/endianness/to_big_endian.hpp>
#include <fcppt/endianness/to_little_endian.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(endianness)
{
	BOOST_CHECK(
		fcppt::endianness::is_little_endian() !=
		fcppt::endianness::is_big_endian());

	BOOST_CHECK(
		(fcppt::endianness::host_format() == fcppt::endianness::format::little && fcppt::endianness::is_little_endian()) ||
		(fcppt::endianness::host_format() == fcppt::endianness::format::big && fcppt::endianness::is_big_endian()));

	int foo = 108;

	BOOST_CHECK(
		(fcppt::endianness::is_little_endian() && fcppt::endianness::to_little_endian(foo) == 108) ||
		(fcppt::endianness::is_big_endian() && fcppt::endianness::to_big_endian(foo) == 108));

	BOOST_CHECK(
		fcppt::endianness::swap(fcppt::endianness::swap(foo)) == foo);

	BOOST_CHECK(
		fcppt::endianness::from_big_endian(fcppt::endianness::to_big_endian(foo)) == 108);

	BOOST_CHECK(
		fcppt::endianness::from_little_endian(fcppt::endianness::to_little_endian(foo)) == 108);
}
