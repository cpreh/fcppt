//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr_fcppt.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/apply_ternary.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
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

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variant_apply_movable
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::variant::object<
		boost::mpl::vector3<
			int_unique_ptr,
			string_unique_ptr,
			bool_unique_ptr
		>
	>
	variant;

	variant int_variant(
		fcppt::make_unique_ptr_fcppt<
			int
		>(
			42
		)
	);

	variant string_variant(
		fcppt::make_unique_ptr_fcppt<
			std::string
		>(
			"test"
		)
	);

	variant bool_variant(
		fcppt::make_unique_ptr_fcppt<
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
