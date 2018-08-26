//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/variant/apply_ternary.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::unique_ptr<
	int
>
int_unique_ptr;

typedef
fcppt::unique_ptr<
	std::string
>
string_unique_ptr;

typedef
fcppt::unique_ptr<
	bool
>
bool_unique_ptr;

struct function
{
	template<
		typename T1,
		typename T2,
		typename T3
	>
	void
	operator()(
		T1 &,
		T2 &,
		T3 &
	) const
	{
		CHECK(
			false
		);
	}

	void
	operator()(
		int_unique_ptr &_int,
		string_unique_ptr &_string,
		bool_unique_ptr &_bool
	) const
	{
		CHECK(
			*_int
			==
			42
		);

		CHECK(
			*_string
			==
			"test"
		);

		CHECK(
			*_bool
		);
	}
};

typedef
std::tuple<
	int_unique_ptr,
	string_unique_ptr,
	bool_unique_ptr
>
move_result;

struct move_function
{
	template<
		typename T1,
		typename T2,
		typename T3
	>
	move_result
	operator()(
		T1 &&,
		T2 &&,
		T3 &&
	) const
	{
		throw
			fcppt::exception{
				FCPPT_TEXT("impossible")
			};
	}

	move_result
	operator()(
		int_unique_ptr &&_int,
		string_unique_ptr &&_string,
		bool_unique_ptr &&_bool
	) const
	{
		return
			move_result{
				std::move(
					_int
				),
				std::move(
					_string
				),
				std::move(
					_bool
				)
			};
	}
};

typedef
fcppt::variant::variadic<
	int_unique_ptr,
	string_unique_ptr,
	bool_unique_ptr
>
variant;

}

TEST_CASE(
	"variant::apply ref",
	"[variant]"
)
{
	variant int_variant(
		fcppt::make_unique_ptr<
			int
		>(
			42
		)
	);

	variant string_variant(
		fcppt::make_unique_ptr<
			std::string
		>(
			"test"
		)
	);

	variant bool_variant(
		fcppt::make_unique_ptr<
			bool
		>(
			true
		)
	);

	function const func{};

	fcppt::variant::apply_ternary(
		func,
		int_variant,
		string_variant,
		bool_variant
	);
}

TEST_CASE(
	"variant_apply move",
	"[variant]"
)
{
	move_result const result{
		fcppt::variant::apply_ternary(
			move_function{},
			variant{
				fcppt::make_unique_ptr<
					int
				>(
					42
				)
			},
			variant{
				fcppt::make_unique_ptr<
					std::string
				>(
					"test"
				)
			},
			variant{
				fcppt::make_unique_ptr<
					bool
				>(
					true
				)
			}
		)
	};

	CHECK(
		*std::get<
			0
		>(
			result
		)
		==
		42
	);

	CHECK(
		*std::get<
			1
		>(
			result
		)
		==
		"test"
	);

	CHECK(
		*std::get<
			2
		>(
			result
		)
	);
}
