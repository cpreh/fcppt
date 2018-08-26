//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::tree copy",
	"[container],[tree]"
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

	CHECK(
		head2.value()
		==
		10
	);

	REQUIRE(
		head2.children().size()
		==
		2u
	);

	fcppt::optional::maybe(
		head2.front(),
		[]{
			CHECK(
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
			CHECK(
				_front.get().value()
				==
				20
			);

			fcppt::optional::maybe(
				_front.get().parent(),
				[]{
					CHECK(
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
					CHECK(
						&_parent.get()
						==
						&head2
					);
				}
			);
		}
	);

	fcppt::optional::maybe(
		head2.back(),
		[]{
			CHECK(
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
			CHECK(
				_back.get().value()
				==
				30
			);

			fcppt::optional::maybe(
				_back.get().parent(),
				[]{
					CHECK(
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
					CHECK(
						&_parent.get()
						==
						&head2
					);
				}
			);
		}
	);
}
