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


#ifndef SGE_CONTAINER_FIELD_IMPL_HPP_INCLUDED
#define SGE_CONTAINER_FIELD_IMPL_HPP_INCLUDED

#include <sge/container/field_decl.hpp>
#include <sge/math/vector/basic_impl.hpp>
#include <sge/math/dim/basic_impl.hpp>
#include <sge/assert.hpp>
#include <algorithm>
#include <iterator>
#include <ostream>

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
sge::container::field<T, ArrayType, Alloc>::field(
	allocator_type const &alloc)
:
	dim_(dim_type::null()),
	array(alloc)
{}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
sge::container::field<T, ArrayType, Alloc>::field(
	field const &r)
:
	dim_(r.dim_),
	array(r.array)
{}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
sge::container::field<T, ArrayType, Alloc>::field(
	dim_type const &dim,
	value_type const &t,
	allocator_type const &alloc)
:
	dim_(dim),
	array(
		field_count(),
		t,
		alloc)
{}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
template<
	typename Iterator
>
sge::container::field<T, ArrayType, Alloc>::field(
	dim_type const &dim_,
	Iterator const b,
	Iterator const e,
	allocator_type const &alloc)
:
	dim_(dim_),
	array(alloc)
{
	array.resize(field_count());
	std::copy(b, e, begin());
}
template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
void
sge::container::field<T, ArrayType, Alloc>::swap(
	field<T, ArrayType, Alloc> &r)
{
	std::swap(
		dim_,
		r.dim_);
	array.swap(
		r.array);
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
sge::container::field<T, ArrayType, Alloc> &
sge::container::field<T, ArrayType, Alloc>::operator=(
	field<T, ArrayType, Alloc> const &r)
{
	if(&r != this)
	{
		dim_ = r.dim_;
		array = r.array;
	}
	return *this;
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::size_type
sge::container::field<T, ArrayType, Alloc>::size() const
{
	return array.size();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::size_type
sge::container::field<T, ArrayType, Alloc>::max_size() const
{
	return array.max_size();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
bool
sge::container::field<T, ArrayType, Alloc>::empty() const
{
	return array.empty();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::iterator
sge::container::field<T, ArrayType, Alloc>::begin()
{
	return array.begin();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::iterator
sge::container::field<T, ArrayType, Alloc>::end()
{
	return array.end();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::const_iterator
sge::container::field<T, ArrayType, Alloc>::begin() const
{
	return array.begin();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::const_iterator
sge::container::field<T, ArrayType, Alloc>::end() const
{
	return array.end();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::reverse_iterator
sge::container::field<T, ArrayType, Alloc>::rbegin()
{
	return array.rbegin();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::reverse_iterator
sge::container::field<T, ArrayType, Alloc>::rend()
{
	return array.rend();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::const_reverse_iterator
sge::container::field<T, ArrayType, Alloc>::rbegin() const
{
	return array.rbegin();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::const_reverse_iterator
sge::container::field<T, ArrayType, Alloc>::rend() const
{
	return array.rend();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::vector_type const
sge::container::field<T, ArrayType, Alloc>::position(
	const_iterator const it) const
{
	difference_type const diff = std::distance(begin(), it);
	return vector_type(
		diff % dim().w(),
		diff / dim().w());
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::iterator
sge::container::field<T, ArrayType, Alloc>::position_it(
	vector_type const &v)
{
	return begin() + v.y() * dim().w() + v.x();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::const_iterator
sge::container::field<T, ArrayType, Alloc>::position_it(
	vector_type const &v) const
{
	return begin() + v.y() * dim().w() + v.x();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::allocator_type
sge::container::field<T, ArrayType, Alloc>::get_allocator() const
{
	return array.get_allocator();
}

template<
	typename Cit,
	typename It>
void copy_overlap_right(
	Cit const source_begin,
	Cit const source_end,
	It const dest_begin)
{
	std::copy_backward(
		source_begin,
		source_end,
		boost::next(
			dest_begin,
			std::distance(source_begin,source_end)));
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
void
sge::container::field<T, ArrayType, Alloc>::resize_canvas(
	dim_type const &n,
	const_reference value)
{
	// dimension hasn't changed?
	if (dim() == n)
		return;

	field new_(
		n,
		value);

	for (vector_type p = vector_type::null(); p.y() < std::min(n.h(),dim().h()); ++p.y())
		for (p.x() = 0; p.x() < std::min(n.w(),dim().h()); ++p.x())
			new_.pos(p) = pos(p);

	swap(
		new_);
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
void
sge::container::field<T, ArrayType, Alloc>::resize(
	dim_type const &n,
	const_reference value)
{
	if (dim_ == n)
		return;

	dim_ = n;

	array.resize(
		field_count(),
		value);
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::value_type &
sge::container::field<T, ArrayType, Alloc>::pos(
	vector_type const &p)
{
	range_check(p);
	return array[static_cast<size_type>(p.y() * dim().w() + p.x())];
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::value_type const &
sge::container::field<T, ArrayType, Alloc>::pos(
	vector_type const &p) const
{
	range_check(p);
	return array[static_cast<size_type>(p.y() * dim().w() + p.x())];
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::reference
sge::container::field<T, ArrayType, Alloc>::front()
{
	return array.front();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::const_reference
sge::container::field<T, ArrayType, Alloc>::front() const
{
	return array.front();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::reference
sge::container::field<T, ArrayType, Alloc>::back()
{
	return array.back();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::const_reference
sge::container::field<T, ArrayType, Alloc>::back() const
{
	return array.back();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::value_type
sge::container::field<T, ArrayType, Alloc>::x(
	const_iterator const p) const
{
	check_w();
	return std::distance(begin(), p) % dim().w();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::value_type
sge::container::field<T, ArrayType, Alloc>::y(
	const_iterator const p) const
{
	check_w();
	return std::distance(begin(),p) / dim().w();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::vector_type const
sge::container::field<T, ArrayType, Alloc>::pos(
	const_iterator const p) const
{
	return vector_type(x(p), y(p));
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::size_type
sge::container::field<T, ArrayType, Alloc>::field_count() const
{
	return dim().content();
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
typename sge::container::field<T, ArrayType, Alloc>::dim_type const
sge::container::field<T, ArrayType, Alloc>::dim() const
{
	return dim_;
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
void
sge::container::field<T, ArrayType, Alloc>::range_check(
	vector_type const &v) const
{
	SGE_ASSERT(v.x() < dim().w() && v.y() < dim().h());
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
void
sge::container::field<T, ArrayType, Alloc>::check_w() const
{
	SGE_ASSERT(dim().w() != 0);
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
bool
sge::container::operator==(
	field<T, ArrayType, Alloc> const &l,
	field<T, ArrayType, Alloc> const &r)
{
	return l.dim() == r.dim()
		&& std::equal(l.begin(), l.end(), r.begin());
}

template<
	typename T,
	template<
		typename,
		typename
	> class ArrayType,
	typename Alloc
>
bool
sge::container::operator!=(
	field<T, ArrayType, Alloc> const &l,
	field<T, ArrayType, Alloc> const &r)
{
	return !(l == r);
}

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
std::basic_ostream<Ch,Traits> &
sge::container::operator<<(
	std::basic_ostream<Ch,Traits> &stream,
	field<T, ArrayType, Alloc> const &f)
{
	typedef field<T, ArrayType, Alloc> field_type;
	typedef typename field_type::size_type size_type;
	typedef typename field_type::vector_type vector_type;

	for (size_type y = 0; y < f.dim().h(); ++y)
	{
		for (size_type x = 0; x < f.dim().w(); ++x)
			stream << f.pos(vector_type(x,y)) << stream.widen(' ');
		stream << stream.widen('\n');
	}
	return stream;
}

#endif
