//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/child_position.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	container_tree_child_position
)
{
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

	fcppt::optional::maybe(
		fcppt::optional::bind(
			test.front(),
			[
				&test
			](
				fcppt::reference<
					int_tree
				> const _child
			){
				return
					fcppt::container::tree::child_position(
						test,
						_child.get()
					);
			}
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
