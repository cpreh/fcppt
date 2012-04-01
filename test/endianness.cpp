//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/endianness/convert.hpp>
#include <fcppt/endianness/host_format.hpp>
#include <fcppt/endianness/is_big_endian.hpp>
#include <fcppt/endianness/is_little_endian.hpp>
#include <fcppt/endianness/swap.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	endianness
)
{
FCPPT_PP_POP_WARNING

	int foo = 108;

	BOOST_CHECK((
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

	BOOST_CHECK(
		fcppt::endianness::swap(
			fcppt::endianness::swap(
				foo
			)
		)
		==
		foo
	);

	BOOST_CHECK((
		fcppt::endianness::convert(
			fcppt::endianness::convert(
				foo,
				fcppt::endianness::format::big
			),
			fcppt::endianness::format::big
		)
		== 108
	));

	BOOST_CHECK((
		fcppt::endianness::convert(
			fcppt::endianness::convert(
				foo,
				fcppt::endianness::format::little
			),
			fcppt::endianness::format::little
		)
		== 108
	));
}
