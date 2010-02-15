//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_RAW_VECTOR_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_DECL_HPP_INCLUDED

#include <fcppt/container/raw_vector_fwd.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_pod.hpp>
#include <iterator>

namespace fcppt
{
namespace container
{

/// A special vector class for pod types
/** This class has the ability to provide uninitialized (POD) memory.
 * An example would be that you need a dynamically growing buffer of char
 * but you don't want to initialize them because this is done by a function
 * like basic_istream::read.
 * The class is restricted to POD types an doesn't call constructors or
 * destructors at its own discretion.
 * Most of the functions are the same as std::vector's functions
 * unless pointed out otherwise.
*/
template<
	typename T,
	typename A
>
class raw_vector
{
	BOOST_STATIC_ASSERT(
		boost::is_pod<
			T
		>::value
	);
public:
	typedef T                                     value_type;
	typedef A                                     allocator_type;
	typedef typename A::size_type                 size_type;
	typedef typename A::difference_type           difference_type;
	typedef typename A::pointer                   pointer;
	typedef typename A::const_pointer             const_pointer;
	typedef typename A::reference                 reference;
	typedef typename A::const_reference           const_reference;
	typedef pointer                               iterator;
	typedef const_pointer                         const_iterator;
	typedef std::reverse_iterator<iterator>       reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	iterator
	begin();

	const_iterator
	begin() const;

	iterator
	end();

	const_iterator
	end() const;

	reverse_iterator
	rbegin();

	const_reverse_iterator
	rbegin() const;

	reverse_iterator
	rend();

	const_reverse_iterator
	rend() const;

	const_iterator
	cbegin() const;

	const_iterator
	cend() const;

	const_reverse_iterator
	crbegin() const;

	const_reverse_iterator
	crend() const;

	reference
	operator[](
		size_type
	);

	const_reference
	operator[](
		size_type
	) const;

	reference
	at(
		size_type
	);

	const_reference
	at(
		size_type
	) const;

	reference
	front();

	const_reference
	front() const;

	reference
	back();

	const_reference
	back() const;

	/// Returns the pointer to the store.
	/** May return 0 if the vector is empty.
	*/
	pointer
	data();

	const_pointer
	data() const;

	/// Returns the pointer to the end of the store.
	/** Equal to data() + size().
	*/
	pointer
	data_end();

	const_pointer
	data_end() const;

	explicit raw_vector(
		A const & = A()
	);

	/// constructs an uninitialized vector
	/** All of the elements will have undeterminate value
	 * and must be written before begin read.
	*/
	explicit raw_vector(
		size_type sz,
		A const & = A()
	);

	raw_vector(
		size_type sz,
		T const &,
		A const & = A()
	);

	template<
		typename In
	>
	raw_vector (
		In beg,
		In end,
		A const & = A()
	);

	raw_vector (
		raw_vector const &
	);

	~raw_vector();

	raw_vector &
	operator=(
		raw_vector const &
	);

	template<
		typename In
	>
	void
	assign(
		In beg,
		In end
	);

	void
	assign(
		size_type n,
		T const &value
	);

	void
	push_back(
		T const &
	);

	void
	pop_back();

	void
	clear();

	size_type
	size() const;

	bool
	empty() const;

	size_type
	max_size() const;

	size_type
	capacity() const;

	void
	swap (
		raw_vector &
	);

	/// The same as resize but doesn't initialize the newly created elements (if any)
	void
	resize_uninitialized(
		size_type sz
	);

	void
	resize(
		size_type sz,
		T const &value = T()
	);

	void
	reserve(
		size_type sz
	);

	allocator_type
	get_allocator() const;

	iterator
	insert(
		iterator position,
		T const &
	);

	void
	insert(
		iterator position,
		size_type n,
		T const &
	);

	template<
		typename In
	>
	void
	insert(
		iterator position,
		In first,
		In last
	);

	iterator
	erase(
		iterator position
	);

	iterator
	erase(
		iterator first,
		iterator last
	);

	/// Tries to shrink capacity() to fit size()
	void
	shrink_to_fit();

	/// Destroy this vector completely, it will then have empty storage
	/** Equivalent to resize(0); shrink_to_fit()
	*/
	void
	free_memory();
private:
	void
	range_check(
		size_type n
	) const;

	size_type
	new_capacity(
		size_type new_size
	) const;

	void
	reallocate(
		size_type new_cap
	);

	void
	set_pointers(
		pointer src,
		size_type sz,
		size_type cap
	);

	void
	deallocate();

	struct impl
	{
		explicit impl(
			A const &
		);

		impl(
			A const &,
			size_type
		);

		A a;

		pointer
			first,
	        	last,
			cap;
	};

	impl i;
};

template<
	typename T,
	typename A
>
bool
operator==(
	raw_vector<T, A> const &,
	raw_vector<T, A> const &
);

template<
	typename T,
	typename A
>
bool
operator<(
	raw_vector<T, A> const &,
	raw_vector<T, A> const &
);

template<
	typename T,
	typename A
>
bool
operator!=(
	raw_vector<T, A> const &,
	raw_vector<T, A> const &
);

template<
	typename T,
	typename A
>
bool
operator>(
	raw_vector<T, A> const &,
	raw_vector<T, A> const &
);

template<
	typename T,
	typename A
>
bool
operator>=(
	raw_vector<T, A> const &,
	raw_vector<T, A> const &
);

template<
	typename T,
	typename A
>
bool
operator<=(
	raw_vector<T, A> const &,
	raw_vector<T, A> const &
);

template<
	typename T,
	typename A
>
void
swap(
	raw_vector<T, A> &,
	raw_vector<T, A> &
);

}
}

#endif
