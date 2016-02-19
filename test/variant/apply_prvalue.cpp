//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/apply_ternary.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{

struct function
{
	template<
		typename T1,
		typename T2,
		typename T3
	>
	bool
	operator()(
		T1 const &,
		T2 const &,
		T3 const &
	) const
	{
		return
			false;
	}

	bool
	operator()(
		bool const _bool,
		int const _int,
		std::string const &_string
	) const
	{
		return
			_bool == false
			&&
			_int == 42
			&&
			_string == "foo";
	}
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variant_apply_prvalue
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::variant::object<
		boost::mpl::vector3<
			bool,
			int,
			std::string
		>
	>
	variant;

	std::string const string(
		"foo"
	);

	BOOST_CHECK(
		fcppt::variant::apply_ternary(
			function(),
			variant(
				false
			),
			variant(
				42
			),
			variant(
				string
			)
		)
	);
}
