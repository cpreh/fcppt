//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/iterator/base_impl.hpp>
#include <fcppt/iterator/types_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace
{

// ![iterator_types]
class my_iterator;

typedef
fcppt::iterator::types<
	my_iterator, // The derived type
	int, // The value type
	int &, // The reference type, which is non const so the iterator is also an output iterator
	std::ptrdiff_t, // The difference type for pointers
	std::random_access_iterator_tag // The iterator category
>
iterator_types;
// ![iterator_types]

// ![iterator_impl]
class my_iterator
:
	public fcppt::iterator::base<iterator_types>
{
public:
	// Random access iterators require a default constructor.
	my_iterator()
	: ptr_{nullptr}
	{}

	explicit
	my_iterator(pointer const _ptr)
	: ptr_{_ptr}
	{}

	reference
	operator*() const
	{
		return *ptr_;
	}

	void
	increment()
	{
		++ptr_;
	}

	bool
	equal(my_iterator const &_other) const
	{
		return ptr_ == _other.ptr_;
	}

	void
	decrement()
	{
		--ptr_;
	}

	void
	advance(difference_type const _distance)
	{
		ptr_ += _distance;
	}

	difference_type
	distance_to(my_iterator const &_other) const
	{
		return _other.ptr_ - ptr_;
	}
private:
	pointer ptr_;
};
// ![iterator_impl]
}

int
main()
{
// ![iterator_example]
	std::array<int,3> array{{1,2,3}};

	my_iterator start(&*array.begin());

	my_iterator it{start};

	++it;

	*it = 5;

	// Array is now {1,5,3}

	// Prints 5
	std::cout << array[1] << '\n';

	// Prints 1
	std::cout << (it - start) << '\n';
// ![iterator_example]

	my_iterator dummy{};

	std::cout << (start == it) << '\n';

	--it;

	it += 1;
}
