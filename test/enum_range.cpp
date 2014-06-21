//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_enum_range.hpp>
#include <fcppt/make_enum_range_start.hpp>
#include <fcppt/make_enum_range_start_end.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class test_enum
{
	test1,
	test2,
	test3,
	fcppt_maximum = test3
};

typedef
std::vector<
	test_enum
>
enum_vector;

void
test(
	fcppt::enum_range<
		test_enum
	> const _range,
	enum_vector const _result
)
{
	enum_vector values;

	for(
		test_enum value
		:
		_range
	)
		values.push_back(
			value
		);

	BOOST_CHECK((
		values
		==
		_result
	));
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	enum_range
)
{

FCPPT_PP_POP_WARNING

	test(
		fcppt::make_enum_range<
			test_enum
		>(),
		enum_vector{
			test_enum::test1,
			test_enum::test2,
			test_enum::test3
		}
	);
}

BOOST_AUTO_TEST_CASE(
	enum_range_start
)
{

FCPPT_PP_POP_WARNING

	test(
		fcppt::make_enum_range_start(
			test_enum::test2
		),
		enum_vector{
			test_enum::test2,
			test_enum::test3
		}
	);
}

BOOST_AUTO_TEST_CASE(
	enum_range_start_end
)
{

FCPPT_PP_POP_WARNING

	test(
		fcppt::make_enum_range_start_end(
			test_enum::test2,
			test_enum::test3
		),
		enum_vector{
			test_enum::test2
		}
	);

	test(
		fcppt::make_enum_range_start_end(
			test_enum::test2,
			test_enum::test2
		),
		enum_vector{}
	);

}
