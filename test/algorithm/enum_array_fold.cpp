//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/enum_array_fold_static.hpp>
#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/container/enum_array.hpp>
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

typedef
fcppt::container::enum_array<
	my_enum,
	int
>
my_array;

struct fold_function
{
	typedef
	int
	result_type;

	template<
		my_enum Enum
	>
	result_type
	operator()() const
	{
		return
			fcppt::cast::enum_to_int<
				result_type
			>(
				Enum
			);
	}
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_enum_array_fold_static
)
{
FCPPT_PP_POP_WARNING

	my_array const array(
		fcppt::algorithm::enum_array_fold_static<
			my_array
		>(
			fold_function{}
		)
	);

	BOOST_CHECK(
		array[
			my_enum::test1
		]
		== 0
	);

	BOOST_CHECK(
		array[
			my_enum::test3
		]
		== 2
	);
}
