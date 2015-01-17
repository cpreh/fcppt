//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/int_range_impl.hpp>
#include <fcppt/make_int_range.hpp>
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/make_literal_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

template<
	typename Int
>
void
test(
	fcppt::int_range<
		Int
	> const _range,
	std::vector<
		Int
	> const &_result
)
{
	std::vector<
		Int
	> values;

	for(
		Int value
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

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	strong_int
);

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	int_range
)
{

FCPPT_PP_POP_WARNING

	test(
		fcppt::make_int_range(
			0,
			3
		),
		std::vector<
			int
		>{
			0,
			1,
			2
		}
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	int_range_count
)
{

FCPPT_PP_POP_WARNING

	test(
		fcppt::make_int_range_count(
			2
		),
		std::vector<
			int
		>{
			0,
			1
		}
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	int_range_count_strong_typedef
)
{

FCPPT_PP_POP_WARNING

	test(
		fcppt::make_int_range_count(
			strong_int(
				2
			)
		),
		std::vector<
			strong_int
		>{
			strong_int(
				0
			),
			strong_int(
				1
			)
		}
	);
}
