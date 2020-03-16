//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::tree move",
	"[container],[tree]"
)
{
	using
	string_tree
	=
	fcppt::container::tree::object<
		std::string
	>;

	string_tree tree1(
		"root"
	);

	tree1.push_back(
		"child1"
	);

	string_tree tree2(
		std::move(
			tree1
		)
	);

	CHECK(
		tree2.value()
		==
		std::string("root")
	);

	CHECK_FALSE(
		tree2.empty()
	);

	fcppt::optional::maybe(
		tree2.front(),
		[]{
			CHECK(
				false
			);
		},
		[
			&tree2
		](
			fcppt::reference<
				string_tree
			> const _front
		)
		{
			CHECK(
				_front.get().value()
				==
				std::string("child1")
			);

			fcppt::optional::maybe(
				_front.get().parent(),
				[]{
					CHECK(
						false
					);
				},
				[
					&tree2
				](
					fcppt::reference<
						string_tree
					> const _parent
				)
				{
					CHECK(
						&_parent.get()
						==
						&tree2
					);
				}
			);
		}
	);

	string_tree tree3(
		"test"
	);

	tree3 =
		std::move(
			tree2
		);

	CHECK(
		tree3.value()
		==
		std::string("root")
	);

	CHECK_FALSE(
		tree3.empty()
	);

	fcppt::optional::maybe(
		tree3.front(),
		[]{
			CHECK(
				false
			);
		},
		[
			&tree3
		](
			fcppt::reference<
				string_tree
			> const _front
		)
		{
			CHECK(
				_front.get().value()
				==
				std::string("child1")
			);

			fcppt::optional::maybe(
				_front.get().parent(),
				[]{
					CHECK(
						false
					);
				},
				[
					&tree3
				](
					fcppt::reference<
						string_tree
					> const _parent
				)
				{
					CHECK(
						&_parent.get()
						==
						&tree3
					);
				}
			);
		}
	);
}

TEST_CASE(
	"container::tree move map",
	"[container],[tree]"
)
{
	using
	string_unique_ptr
	=
	fcppt::unique_ptr<
		std::string
	>;

	using
	string_unique_ptr_tree
	=
	fcppt::container::tree::object<
		string_unique_ptr
	>;

	using
	string_unique_ptr_tree_vector
	=
	std::vector<
		string_unique_ptr_tree
	>;

	using
	string_vector
	=
	std::vector<
		std::string
	>;

	string_vector const strings{
		"foo",
		"bar"
	};

	auto const result(
		fcppt::algorithm::map<
			string_unique_ptr_tree_vector
		>(
			strings,
			[](
				std::string const &_value
			)
			{
				return
					string_unique_ptr_tree(
						fcppt::make_unique_ptr<
							std::string
						>(
							_value
						)
					);
			}
		)
	);

	REQUIRE(
		strings.size()
		==
		result.size()
	);

	CHECK(
		*result.at(
			0
		).value()
		==
		std::string("foo")
	);

	CHECK(
		*result.at(
			1
		).value()
		==
		std::string("bar")
	);
}
