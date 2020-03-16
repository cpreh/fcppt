//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/literal.hpp>
#include <fcppt/make_literal_boost_units.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/length.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"literal boost_units",
	"[literal]"
)
{
	typedef
	boost::units::quantity<
		boost::units::si::length,
		int
	>
	length;

	CHECK(
		fcppt::literal<
			length
		>(
			2
		).value()
		==
		2
	);
}
