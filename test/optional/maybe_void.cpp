//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/maybe_void.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <memory>
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	maybe_void_ref
)
{
FCPPT_PP_POP_WARNING

	int result{
		0
	};

	typedef
	fcppt::optional<
		int &
	>
	optional_int_ref;

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
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	maybe_void_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional<
		int_unique_ptr
	>
	optional_int_unique_ptr;

	fcppt::maybe_void(
		optional_int_unique_ptr(
			fcppt::make_unique_ptr<
				int
			>(
				42
			)
		),
		[](
			int_unique_ptr &&_ptr
		)
		{
			BOOST_CHECK_EQUAL(
				*_ptr,
				42
			);
		}
	);
}
