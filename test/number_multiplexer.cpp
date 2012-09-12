//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/homogenous_pair.hpp>
#include <fcppt/number_multiplexer/object.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	number_multiplexer
)
{
FCPPT_PP_POP_WARNING
	typedef
	fcppt::number_multiplexer::object<unsigned>
	multiplexer;

	multiplexer m;

	m.append(
		multiplexer::bit_count(
			3u),
		7u);

	BOOST_REQUIRE(
		m.value() == 7);

	m.append(
		multiplexer::bit_count(
			3u),
		7u);

	BOOST_CHECK(
		m.value() == 63);
}
