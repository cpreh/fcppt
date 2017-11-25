//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	container_tree_copy
)
{
	typedef
	fcppt::container::tree::object<
		int
	>
	i_tree;

	i_tree head(
		10
	);

	head.push_back(
		20
	);

	head.push_back(
		30
	);

	i_tree const head2(
		head
	);

	BOOST_CHECK_EQUAL(
		head2.value(),
		10
	);

	BOOST_REQUIRE_EQUAL(
		head2.children().size(),
		2u
	);

	fcppt::optional::maybe(
		head2.front(),
		[]{
			BOOST_CHECK(
				false
			);
		},
		[
			&head2
		](
			fcppt::reference<
				i_tree const
			> const _front
		)
		{
			BOOST_CHECK_EQUAL(
				_front.get().value(),
				20
			);

			fcppt::optional::maybe(
				_front.get().parent(),
				[]{
					BOOST_CHECK(
						false
					);
				},
				[
					&head2
				](
					fcppt::reference<
						i_tree const
					> const _parent
				)
				{
					BOOST_CHECK_EQUAL(
						&_parent.get(),
						&head2
					);
				}
			);
		}
	);

	fcppt::optional::maybe(
		head2.back(),
		[]{
			BOOST_CHECK(
				false
			);
		},
		[
			&head2
		](
			fcppt::reference<
				i_tree const
			> const _back
		)
		{
			BOOST_CHECK_EQUAL(
				_back.get().value(),
				30
			);

			fcppt::optional::maybe(
				_back.get().parent(),
				[]{
					BOOST_CHECK(
						false
					);
				},
				[
					&head2
				](
					fcppt::reference<
						i_tree const
					> const _parent
				)
				{
					BOOST_CHECK_EQUAL(
						&_parent.get(),
						&head2
					);
				}
			);
		}
	);
}
