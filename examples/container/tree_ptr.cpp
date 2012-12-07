//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/tree/object.hpp>
#include <fcppt/container/tree/ptr_value.hpp>
#include <fcppt/container/tree/release.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace
{

// create a class that is not copyable
class noncopyable
{
	FCPPT_NONCOPYABLE(
		noncopyable
	);
public:
	explicit
	noncopyable(
		int const _value
	)
	:
		value_(
			_value
		)
	{
	}

	int
	int_value() const
	{
		return value_;
	}
private:
	int const value_;
};

}

int main()
{
	// typedef the tree object to use ptr_container semantics
	typedef
	fcppt::container::tree::object<
		fcppt::container::tree::ptr_value<
			noncopyable
		>
	>
	noncopyable_tree;

	// the constructor argument now expects a unique_ptr
	noncopyable_tree node(
		fcppt::make_unique_ptr<
			noncopyable
		>(
			42
		)
	);

	// tree::object::value still returns a reference
	// prints 42
	fcppt::io::cout()
		<< node.value().int_value()
		<< FCPPT_TEXT('\n');

	// we can also release the held value
//! [tree_ptr_release]
	typedef std::unique_ptr<
		noncopyable
	> noncopyable_unique_ptr;

	noncopyable_unique_ptr released(
		fcppt::container::tree::release(
			node
		)
	);

//! [tree_ptr_release]
	// check that the internal scoped_ptr is now empty
	// prints false
	fcppt::io::cout()
		<<
		std::boolalpha
		<<
			static_cast<
				bool
			>(
				node.holder()
			)
		<<
		FCPPT_TEXT('\n');

	// output the obtained unique_ptr
	// prints 42
	fcppt::io::cout()
		<< released->int_value()
		<< FCPPT_TEXT('\n');
}
//]
