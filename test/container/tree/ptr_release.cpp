//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/ptr_value.hpp>
#include <fcppt/container/tree/release.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_tree_ptr_release
)
{
FCPPT_PP_POP_WARNING

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
