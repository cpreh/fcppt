//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/container/tree/tree.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


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

}

BOOST_AUTO_TEST_CASE(
	container_tree_ptr_release
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
			42
		)
	);

	BOOST_REQUIRE(
		tree.value().value() == 42
	);

	fcppt::unique_ptr<
		noncopyable
	> released(
		fcppt::container::tree::release(
			tree
		)
	);

	BOOST_REQUIRE(
		!tree.holder()
	);

	BOOST_REQUIRE(
		released->value() == 42
	);
}
