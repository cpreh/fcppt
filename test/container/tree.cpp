//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/tree.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <boost/test/unit_test.hpp>
#include <algorithm>

namespace
{

typedef fcppt::container::tree::object<
	unsigned
> ui_tree;

}

template class fcppt::container::tree::object<
	unsigned
>;

BOOST_AUTO_TEST_CASE(
	container_tree_equal
)
{
	ui_tree tree1(
		42
	);

	tree1.push_back(
		100
	);

	ui_tree tree2(
		42
	);

	tree2.push_back(
		100
	);

	BOOST_REQUIRE(
		tree1 == tree2
	);

	tree2.push_back(
		200
	);

	BOOST_REQUIRE(
		tree1 != tree2
	);
}

BOOST_AUTO_TEST_CASE(
	container_tree_swap
)
{
	ui_tree tree1(
		10
	);

	tree1.push_back(
		20
	);

	ui_tree tree2(
		30
	);

	std::swap(
		tree1,
		tree2
	);

	BOOST_REQUIRE(
		tree1.value() == 30
		&& tree2.value() == 10
		&& !tree2.empty()
		&& tree2.front().value() == 20
	);
}

BOOST_AUTO_TEST_CASE(
	container_tree_pre_order
)
{
	ui_tree tree(
		1
	);

	tree.push_back(
		2
	);

	tree.front().push_back(
		3
	);

	tree.front().push_back(
		4
	);

	tree.push_back(
		5
	);

	tree.push_back(
		6
	);

	typedef fcppt::container::tree::pre_order<
		ui_tree const
	> traversal_type;

	traversal_type const trav(
		tree
	);

	traversal_type::iterator it(
		trav.begin()
	);

	BOOST_REQUIRE(
		it->value() == 1
	);

	++it;

	BOOST_REQUIRE(
		it->value() == 2
	);

	++it;

	BOOST_REQUIRE(
		it->value() == 3
	);

	++it;

	BOOST_REQUIRE(
		it->value() == 4
	);

	++it;

	BOOST_REQUIRE(
		it->value() == 5
	);

	++it;

	BOOST_REQUIRE(
		it->value() == 6
	);

	++it;

	BOOST_REQUIRE(
		it == trav.end()
	);
}

namespace
{

struct noncopyable
{
	FCPPT_NONCOPYABLE(
		noncopyable
	);
public:
	explicit noncopyable(
		int	
	);

	~noncopyable();

	int
	value() const;
private:
	int const value_;
};

noncopyable::noncopyable(
	int const _value
)
:
	value_(_value)
{
}

noncopyable::~noncopyable()
{
}

int
noncopyable::value() const
{
	return value_;
}

typedef fcppt::container::tree::object<
	fcppt::container::tree::ptr_value<
		noncopyable
	>
> nc_tree;

}

template class
fcppt::container::tree::object<
	fcppt::container::tree::ptr_value<
		noncopyable
	>
>;

BOOST_AUTO_TEST_CASE(
	container_ptr_tree
)
{
	nc_tree tree(	
		fcppt::make_unique_ptr<
			noncopyable
		>(
			42
		)
	);

	BOOST_REQUIRE(
		tree.value().value() == 42
	);
}
