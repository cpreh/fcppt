//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/runtime_enum.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class my_enum
{
	test1,
	test2,
	test3,
	fcppt_maximum = test3
};

struct function
{
	typedef
	bool
	result_type;

	template<
		typename Enum
	>
	bool
	operator()(
		Enum
	) const
	{
		return
			Enum::value
			==
			my_enum::test3;
	}
};

}


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	codecvt_widen
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		fcppt::runtime_enum(
			my_enum::test3,
			function()
		)
	);
}
