//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional_impl.hpp>
#include <fcppt/maybe_void.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	maybe_void
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
		int &
	>
	optional_int_ref;

	int result{
		0
	};

	fcppt::maybe_void(
		optional_int(
			10
		),
		[
			&result
		](
			int const _val
		)
		{
			result =
				_val;
		}
	);

	BOOST_CHECK(
		result
		==
		10
	);

	fcppt::maybe_void(
		optional_int(),
		[
			&result
		](
			int const _val
		)
		{
			result =
				_val;
		}
	);

	BOOST_CHECK(
		result
		==
		10
	);

	fcppt::maybe_void(
		optional_int_ref(
			result
		),
		[](
			int &_val
		)
		{
			_val = 42;
		}
	);

	BOOST_CHECK(
		result
		==
		42
	);

	optional_int temp(
		0
	);

	fcppt::maybe_void(
		temp,
		[](
			int &_val
		)
		{
			_val = 30;
		}
	);

	BOOST_CHECK(
		temp.get_unsafe()
		==
		30
	);
}
