/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_CONTAINER_FIELD_DECL_HPP_INCLUDED
#define SGE_CONTAINER_FIELD_DECL_HPP_INCLUDED

#include <sge/container/field_fwd.hpp>
#include <sge/math/vector/static.hpp>
#include <sge/math/dim/static.hpp>
#include <sge/math/dim/basic_decl.hpp>
#include <iterator>
#include <iosfwd>

namespace sge
{
namespace container
{

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
class field
{
	public:
	typedef ArrayType<T,Alloc>                    array_type;

	typedef T                                     value_type;
	typedef Alloc                                 allocator_type;
	typedef T&                                    reference;
	typedef const T&                              const_reference;
	typedef typename array_type::iterator         iterator;
	typedef typename array_type::const_iterator   const_iterator;
	typedef typename array_type::size_type        size_type;
	typedef typename array_type::difference_type  difference_type;
	typedef std::reverse_iterator<iterator>       reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	typedef typename math::vector::static_<size_type,2>::type      vector_type;
	typedef typename math::dim::static_<size_type,2>::type         dim_type;

	explicit field(
		allocator_type const &alloc = allocator_type());

	field(
		field const &r);

	explicit field(
		dim_type const &dim,
		value_type const &t = value_type(),
		allocator_type const &alloc = allocator_type());

	template<
		typename Iterator
	>
	field(
		dim_type const &dim_,
		Iterator b,
		Iterator e,
		allocator_type const &alloc = allocator_type());

	void swap(
		field &r);

	field &
	operator=(
		field const &r);

	size_type size() const;
	size_type max_size() const;
	bool empty() const;
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;

	vector_type const
	position(
		const_iterator it) const;

	iterator position_it(
		vector_type const &);

	const_iterator
	position_it(
		vector_type const &) const;

	allocator_type
	get_allocator() const;

	void resize_canvas(
		dim_type const &n,
		const_reference value = value_type());

	void resize(
		dim_type const &n,
		const_reference value = value_type());

	value_type &
	pos_mod(
		vector_type const &);

	value_type const &
	pos_mod(
		vector_type const &p) const;

	value_type &
	pos(
		vector_type const &p);

	value_type const &
	pos(
		vector_type const &p) const;

	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;

	value_type
	x(
		const_iterator) const;

	value_type
	y(
		const_iterator) const;

	vector_type const
	pos(
		const_iterator p) const;

	size_type field_count() const;
	dim_type const dim() const;
private:
	void range_check(
		vector_type const &) const;
	void check_w() const;

	dim_type   dim_;
	array_type array;
};


template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
bool operator==(
	field<T, ArrayType, Alloc> const &l,
	field<T, ArrayType, Alloc> const &r);

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
bool operator!=(
	field<T, ArrayType, Alloc> const &l,
	field<T, ArrayType, Alloc> const &r);

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc,
	typename Ch,
	typename Traits
>
std::basic_ostream<Ch, Traits> &
operator<<(
	std::basic_ostream<Ch, Traits> &,
	field<T, ArrayType, Alloc> const &);

}
}

#endif
