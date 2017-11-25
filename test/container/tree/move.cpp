//          Copyright Carl Philipp Reh 2009 - 2017.
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
#include <boost/test/unit_test.hpp>
#include <string>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	container_tree_move
)
{
	typedef
	fcppt::container::tree::object<
		std::string
	>
	string_tree;

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

	BOOST_CHECK(
		tree1.empty()
	);

	BOOST_CHECK_EQUAL(
		tree2.value(),
		std::string("root")
	);

	BOOST_CHECK(
		!tree2.empty()
	);

	fcppt::optional::maybe(
		tree2.front(),
		[]{
			BOOST_CHECK(
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
			BOOST_CHECK_EQUAL(
				_front.get().value(),
				std::string("child1")
			);

			fcppt::optional::maybe(
				_front.get().parent(),
				[]{
					BOOST_CHECK(
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
					BOOST_CHECK_EQUAL(
						&_parent.get(),
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

	BOOST_CHECK(
		tree2.empty()
	);

	BOOST_CHECK_EQUAL(
		tree3.value(),
		std::string("root")
	);

	BOOST_CHECK(
		!tree3.empty()
	);

	fcppt::optional::maybe(
		tree3.front(),
		[]{
			BOOST_CHECK(
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
			BOOST_CHECK_EQUAL(
				_front.get().value(),
				std::string("child1")
			);

			fcppt::optional::maybe(
				_front.get().parent(),
				[]{
					BOOST_CHECK(
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
					BOOST_CHECK_EQUAL(
						&_parent.get(),
						&tree3
					);
				}
			);
		}
	);
}

BOOST_AUTO_TEST_CASE(
	container_tree_move_map
)
{
	typedef
	fcppt::unique_ptr<
		std::string
	>
	string_unique_ptr;

	typedef
	fcppt::container::tree::object<
		string_unique_ptr
	>
	string_unique_ptr_tree;

	typedef
	std::vector<
		string_unique_ptr_tree
	>
	string_unique_ptr_tree_vector;

	typedef
	std::vector<
		std::string
	>
	string_vector;

	string_vector const strings{
		"foo",
		"bar"
	};

	string_unique_ptr_tree_vector const result(
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

	BOOST_REQUIRE_EQUAL(
		strings.size(),
		result.size()
	);

	BOOST_CHECK_EQUAL(
		*result.at(
			0
		).value(),
		std::string("foo")
	);

	BOOST_CHECK_EQUAL(
		*result.at(
			1
		).value(),
		std::string("bar")
	);
}
