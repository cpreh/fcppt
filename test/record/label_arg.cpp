//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)



#include <fcppt/record/element.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label_arg.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{

FCPPT_RECORD_MAKE_LABEL_ARG(
	texture,
	unsigned
);

}

BOOST_AUTO_TEST_CASE(
	record_arg_label
)
{
	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			texture<0>,
			std::string
		>,
		fcppt::record::element<
			texture<1>,
			std::string
		>
	>
	record_type;

	record_type const test_sprite{
		texture<0>{} = std::string("ground"),
		texture<1>{} = std::string("clouds")
	};

	BOOST_CHECK_EQUAL(
		fcppt::record::get<
			texture<0>
		>(
			test_sprite
		),
		std::string("ground")
	);

	BOOST_CHECK_EQUAL(
		fcppt::record::get<
			texture<1>
		>(
			test_sprite
		),
		std::string("clouds")
	);
}
