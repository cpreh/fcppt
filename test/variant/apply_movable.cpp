//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/assert/unreachable.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/apply_ternary.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
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
	bool
	operator()(
		T1 &,
		T2 &,
		T3 &
	) const
	{
		return
			false;
	}

	bool
	operator()(
		int_unique_ptr &_int,
		string_unique_ptr &_string,
		bool_unique_ptr &_bool
	) const
	{
		return
			*_int == 42
			&&
			*_string == "test"
			&&
			*_bool == true;
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
		FCPPT_ASSERT_UNREACHABLE;
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
fcppt::variant::object<
	boost::mpl::vector3<
		int_unique_ptr,
		string_unique_ptr,
		bool_unique_ptr
	>
>
variant;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variant_apply_movable
)
{
FCPPT_PP_POP_WARNING

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

	BOOST_CHECK(
		fcppt::variant::apply_ternary(
			func,
			int_variant,
			string_variant,
			bool_variant
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variant_apply_move
)
{
FCPPT_PP_POP_WARNING

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

	BOOST_CHECK_EQUAL(
		*std::get<
			0
		>(
			result
		),
		42
	);

	BOOST_CHECK_EQUAL(
		*std::get<
			1
		>(
			result
		),
		"test"
	);

	BOOST_CHECK(
		*std::get<
			2
		>(
			result
		)
	);
}
