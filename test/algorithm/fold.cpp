//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/fold.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <functional>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_fold
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::vector<
		int
	>
	int_vector;

	typedef
	std::vector<
		int_vector
	>
	int_vector_vector;

	int_vector_vector const vectors{
		int_vector{
			1,
			2
		},
		int_vector{
			3,
			4
		}
	};

	int const sum(
		fcppt::algorithm::fold(
			vectors,
			0,
			[](
				int_vector const &_vec,
				int const _sum
			)
			{
				return
					fcppt::algorithm::fold(
						_vec,
						_sum,
						std::plus<
							int
						>()
					);
			}
		)
	);

	BOOST_CHECK_EQUAL(
		sum,
		10
	);
}
