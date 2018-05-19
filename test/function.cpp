//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/function.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


template
class
fcppt::function<
	int (
		int
	)
>;

TEST_CASE(
	"function",
	"[various]"
)
{
	typedef
	fcppt::function<
		int (
			int
		)
	>
	function_type;

	function_type const fun{
		[](
			int const _val
		)
		{
			return
				_val
				+
				10;
		}
	};

	CHECK(
		fun(
			10
		)
		==
		20
	);
}


TEST_CASE(
	"function move",
	"[various]"
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::function<
		int (
			int_unique_ptr &&
		)
	>
	function_type;

	function_type const fun{
		[](
			int_unique_ptr &&_val
		)
		{
			return
				*_val
				+
				10;
		}
	};

	CHECK(
		fun(
			fcppt::make_unique_ptr<
				int
			>(
				10
			)
		)
		==
		20
	);
}
