//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/container/grid/object_fwd.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/dim/basic_decl.hpp>
#include <iterator>
#include <iosfwd>

//[grid_decl
namespace fcppt
{
namespace container
{
namespace grid
{

template
<
	typename ArrayType,
	size_type N
>
class object
{
public:
	typedef ArrayType array_type;

	typedef typename ArrayType::value_type value_type;
	typedef typename ArrayType::allocator_type allocator_type;
	typedef typename ArrayType::reference reference;
	typedef typename ArrayType::const_reference const_reference;
	typedef typename array_type::iterator iterator;
	typedef typename array_type::const_iterator const_iterator;
	typedef typename array_type::size_type size_type;
	typedef typename array_type::difference_type difference_type;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	typedef value_type scalar;
	typedef typename math::vector::static_<size_type,N>::type vector;
	typedef typename math::dim::static_<size_type,N>::type dim;

	explicit 
	object(
		allocator_type const &alloc = allocator_type());

	object(
		object const &r
	);

	explicit object(
		dim const &,
		value_type const & = value_type(),
		allocator_type const & = allocator_type()
	);

	template<
		typename Iterator
	>
	explicit
	object(
		dim const &,
		Iterator begin,
		Iterator end,
		allocator_type const & = allocator_type()
	);

	object &
	operator=(
		object const &
	);

	size_type
	size() const;

	size_type
	max_size() const;

	bool
	empty() const;

	iterator
	begin();

	iterator
	end();

	const_iterator
	begin() const;

	const_iterator
	end() const;

	reverse_iterator
	rbegin();

	reverse_iterator
	rend();

	const_reverse_iterator
	rbegin() const;

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

	allocator_type
	get_allocator() const;

	void
	resize_plain(
		dim const &,
		const_reference = value_type()
	);

	void
	resize(
		dim const &,
		const_reference = value_type()
	);

	value_type &
	pos(
		vector const &
	);

	value_type const &
	pos(
		vector const &
	) const;

	reference
	front();

	const_reference
	front() const;

	reference
	back();

	const_reference
	back() const;

	dim const &
	dimension() const;

	void
	swap(
		object &
	);
//<-
private:
	void
	copy_layer(
		object &,
		const_iterator,
		const_iterator,
		iterator,
		size_type);

	void
	range_check(
		vector const &
	) const;

	dim dimension_;
	array_type array_;
//->
};

template<
	typename ArrayType,
	size_type N
>
void
swap(
	object<ArrayType,N> &,
	object<ArrayType,N> &
);

template<
	typename ArrayType,
	size_type N
>
bool
operator==(
	object<ArrayType,N> const &,
	object<ArrayType,N> const &
);

template<
	typename ArrayType,
	size_type N
>
bool
operator!=(
	object<ArrayType,N> const &l,
	object<ArrayType,N> const &r
);

template<
	typename ArrayType,
	size_type N,
	typename Ch,
	typename Traits
>
std::basic_ostream<Ch, Traits> &
operator<<(
	std::basic_ostream<Ch, Traits> &,
	object<ArrayType,N> const &
);

}
}
}
//]

#endif
