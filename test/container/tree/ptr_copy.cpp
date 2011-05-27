//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/tree.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/unique_ptr.hpp>
#include <boost/test/unit_test.hpp>

namespace
{

class noncopyable
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

fcppt::unique_ptr<
	noncopyable
>
copy_tree_value(
	noncopyable const &_other
)
{
	return
		fcppt::make_unique_ptr<
			noncopyable
		>(
			_other.value()
		);
}

}

BOOST_AUTO_TEST_CASE(
	container_tree_ptr_copy
)
{
	typedef fcppt::container::tree::object<
		fcppt::container::tree::ptr_value<
			noncopyable
		>
	> nc_tree;

	nc_tree tree(
		fcppt::make_unique_ptr<
			noncopyable
		>(
			10
		)
	);

	tree.push_back(
		fcppt::make_unique_ptr<
			noncopyable
		>(
			20
		)
	);

	tree.push_back(
		fcppt::make_unique_ptr<
			noncopyable
		>(
			30
		)
	);

	nc_tree copied(
		tree
	);

	BOOST_REQUIRE(
		copied.value().value() == 10
	);

	BOOST_REQUIRE(
		copied.children().size() == 2u
	);

	BOOST_REQUIRE(
		copied.front().value().value() == 20
	);

	BOOST_REQUIRE(
		copied.back().value().value() == 30
	);

	BOOST_REQUIRE(
		copied.front().has_parent()
		&&
		&copied.front().parent()
		== &copied
	);

	BOOST_REQUIRE(
		copied.back().has_parent()
		&&
		&copied.back().parent()
		== &copied
	);
}
