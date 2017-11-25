//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	maybe_void
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	int result{
		0
	};

	fcppt::optional::maybe_void(
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

	BOOST_CHECK_EQUAL(
		result,
		10
	);

	fcppt::optional::maybe_void(
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

	BOOST_CHECK_EQUAL(
		result,
		10
	);

	optional_int temp(
		0
	);

	fcppt::optional::maybe_void(
		temp,
		[](
			int &_val
		)
		{
			_val = 30;
		}
	);

	BOOST_CHECK_EQUAL(
		temp,
		optional_int(
			30
		)
	);
}

BOOST_AUTO_TEST_CASE(
	maybe_void_ref
)
{
	int result{
		0
	};

	typedef
	fcppt::optional::reference<
		int
	>
	optional_int_ref;

	fcppt::optional::maybe_void(
		optional_int_ref{
			fcppt::make_ref(
				result
			)
		},
		[](
			fcppt::reference<
				int
			> const _val
		)
		{
			_val.get() = 42;
		}
	);

	BOOST_CHECK_EQUAL(
		result,
		42
	);
}

BOOST_AUTO_TEST_CASE(
	maybe_void_move
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional::object<
		int_unique_ptr
	>
	optional_int_unique_ptr;

	fcppt::optional::maybe_void(
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
