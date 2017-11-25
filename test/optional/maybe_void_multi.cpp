//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/to_signed.hpp>
#include <fcppt/optional/maybe_void_multi.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	maybe_void_multi
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	typedef
	fcppt::optional::object<
		unsigned
	>
	optional_unsigned;

	int result{
		0
	};

	fcppt::optional::maybe_void_multi(
		[
			&result
		](
			int const _val1,
			unsigned const _val2
		)
		{
			result =
				_val1
				+
				fcppt::cast::to_signed(
					_val2
				);
		},
		optional_int(
			10
		),
		optional_unsigned(
			20
		)
	);

	BOOST_CHECK(
		result
		==
		30
	);
}
