//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/endianness/convert.hpp>
#include <fcppt/endianness/format.hpp>
#include <fcppt/endianness/host_format.hpp>
#include <fcppt/endianness/is_big_endian.hpp>
#include <fcppt/endianness/is_little_endian.hpp>
#include <fcppt/endianness/swap.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"endianness",
	"[endianness]"
)
{
	int const foo{
		108
	};

	CHECK((
		(
			fcppt::endianness::is_little_endian()
			&&
			fcppt::endianness::convert(
				foo,
				fcppt::endianness::format::little
			)
			==
			108
		)
		||
		(
			fcppt::endianness::is_big_endian()
			&&
			fcppt::endianness::convert(
				foo,
				fcppt::endianness::format::big
			)
			==
			108
		)
	));

	CHECK(
		fcppt::endianness::swap(
			fcppt::endianness::swap(
				foo
			)
		)
		==
		foo
	);

	CHECK(
		fcppt::endianness::convert(
			fcppt::endianness::convert(
				foo,
				fcppt::endianness::format::big
			),
			fcppt::endianness::format::big
		)
		==
		108
	);

	CHECK(
		fcppt::endianness::convert(
			fcppt::endianness::convert(
				foo,
				fcppt::endianness::format::little
			),
			fcppt::endianness::format::little
		)
		==
		108
	);
}
