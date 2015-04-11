//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional_impl.hpp>
#include <fcppt/maybe_void_multi.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	maybe_void_multi
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional<
		int
	>
	optional_int;

	typedef
	fcppt::optional<
		unsigned
	>
	optional_unsigned;

	int result{
		0
	};

	fcppt::maybe_void_multi(
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
