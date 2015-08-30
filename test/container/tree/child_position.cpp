//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/maybe.hpp>
#include <fcppt/container/tree/child_position.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_tree_child_position
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::tree::object<
		int
	>
	int_tree;

	int_tree test{
		42,
		int_tree::child_list{
			int_tree{
				1
			},
			int_tree{
				2
			}
		}
	};

	fcppt::maybe(
		fcppt::container::tree::child_position(
			test,
			test.front()
		),
		[]{
			BOOST_CHECK(
				false
			);
		},
		[
			&test
		](
			int_tree::iterator const _pos
		)
		{
			BOOST_CHECK(
				_pos
				==
				test.begin()
			);
		}
	);
}
