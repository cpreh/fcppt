//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/sequence_iteration.hpp>
#include <fcppt/algorithm/update_action.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_sequence_iteration
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::vector<
		int
	>
	sequence;

	sequence seq{
		1,
		2,
		3,
		4
	};

	fcppt::algorithm::sequence_iteration(
		seq,
		[](
			int const _value
		)
		{
			return
				_value
				%
				2
				==
				0
				?
					fcppt::algorithm::update_action::keep
				:
					fcppt::algorithm::update_action::remove
				;
		}
	);

	BOOST_CHECK((
		seq
		==
		sequence{
			2,
			4
		}
	));
}
