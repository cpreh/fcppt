//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/public_config.hpp>
#include <fcppt/literal.hpp>
#if defined(FCPPT_BOOST_SUPPORT)
#include <fcppt/make_literal_boost_units.hpp>
#endif
#include <fcppt/make_literal_strong_typedef.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#if defined(FCPPT_BOOST_SUPPORT)
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/length.hpp>
#endif
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"literal fundamental",
	"[literal]"
)
{
	CHECK(
		fcppt::literal<
			unsigned
		>(
			2
		)
		==
		2u
	);
}

#if defined(FCPPT_BOOST_SUPPORT)
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
#endif

TEST_CASE(
	"literal strong_typedef",
	"[literal]"
)
{
	FCPPT_MAKE_STRONG_TYPEDEF(
		int,
		my_type
	);

	CHECK(
		fcppt::literal<
			my_type
		>(
			1
		).get()
		==
		1
	);
}
