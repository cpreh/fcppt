//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/variant/to_optional.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	variant_to_optional
)
{
	typedef
	fcppt::variant::variadic<
		int,
		std::string
	>
	variant;

	variant const var(
		42
	);

	BOOST_CHECK_EQUAL(
		fcppt::variant::to_optional<
			int
		>(
			var
		),
		fcppt::optional::object<
			int
		>(
			42
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::variant::to_optional<
			std::string
		>(
			var
		),
		fcppt::optional::object<
			std::string
		>()
	);
}

BOOST_AUTO_TEST_CASE(
	variant_to_optional_move
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::variant::variadic<
		int,
		int_unique_ptr
	>
	variant;

	BOOST_CHECK_EQUAL(
		*fcppt::variant::to_optional<
			int_unique_ptr
		>(
			variant(
				fcppt::make_unique_ptr<
					int
				>(
					42
				)
			)
		).get_unsafe(),
		42
	);
}
