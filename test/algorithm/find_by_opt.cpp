//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional_comparison.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/algorithm/find_by_opt.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_find_by_opt
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const vec{
		1,
		2,
		3
	};

	typedef
	fcppt::optional<
		std::string
	>
	result_type;

	BOOST_CHECK(
		fcppt::algorithm::find_by_opt(
			vec,
			[](
				int const _i
			)
			->
			result_type
			{
				return
					(_i % 2 == 0)
					?
						result_type(
							std::string(
								"test"
							)
						)
					:
						result_type()
					;
			}
		)
		==
		result_type(
			std::string(
				"test"
			)
		)
	);

	BOOST_CHECK(
		!fcppt::algorithm::find_by_opt(
			vec,
			[](
				int const _i
			)
			->
			result_type
			{
				return
					_i == 4
					?
						result_type(
							std::string(
								"test"
							)
						)
					:
						result_type()
					;

			}
		)
	);
}
