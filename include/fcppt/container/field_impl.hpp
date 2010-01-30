//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_FIELD_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_FIELD_IMPL_HPP_INCLUDED

#include <fcppt/container/field_decl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/assert.hpp>
#include <algorithm>
#include <iterator>
#include <ostream>

template<
	typename ArrayType
>
fcppt::container::field<ArrayType>::field(
	allocator_type const &alloc
)
:
	dimension_(dim::null()),
	array(alloc)
{}

template<
	typename ArrayType
>
fcppt::container::field<ArrayType>::field(
	field const &r
)
:
	dimension_(r.dimension_),
	array(r.array)
{}

template<
	typename ArrayType
>
fcppt::container::field<ArrayType>::field(
	dim const &dimension_,
	value_type const &t,
	allocator_type const &alloc
)
:
	dimension_(dimension_),
	array(
		size(),
		t,
		alloc
	)
{}

template<
	typename ArrayType
>
template<
	typename Iterator
>
fcppt::container::field<ArrayType>::field(
	dim const &dimension_,
	Iterator const b,
	Iterator const e,
	allocator_type const &alloc
)
:
	dimension_(dimension_),
	array(alloc)
{
	array.resize(
		size()
	);

	std::copy(b, e, begin());
}

template<
	typename ArrayType
>
void
fcppt::container::field<ArrayType>::swap(
	field<ArrayType> &r
)
{
	std::swap(
		dimension_,
		r.dimension_
	);

	array.swap(
		r.array
	);
}

template<
	typename ArrayType
>
fcppt::container::field<ArrayType> &
fcppt::container::field<ArrayType>::operator=(
	field<ArrayType> const &r
)
{
	if(&r != this)
	{
		dimension_ = r.dimension_;
		array = r.array;
	}

	return *this;
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::size_type
fcppt::container::field<ArrayType>::size() const
{
	return dimension_.content();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::size_type
fcppt::container::field<ArrayType>::max_size() const
{
	return array.max_size();
}

template<
	typename ArrayType
>
bool
fcppt::container::field<ArrayType>::empty() const
{
	return array.empty();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::iterator
fcppt::container::field<ArrayType>::begin()
{
	return array.begin();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::iterator
fcppt::container::field<ArrayType>::end()
{
	return array.end();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::const_iterator
fcppt::container::field<ArrayType>::begin() const
{
	return array.begin();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::const_iterator
fcppt::container::field<ArrayType>::end() const
{
	return array.end();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::reverse_iterator
fcppt::container::field<ArrayType>::rbegin()
{
	return array.rbegin();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::reverse_iterator
fcppt::container::field<ArrayType>::rend()
{
	return array.rend();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::const_reverse_iterator
fcppt::container::field<ArrayType>::rbegin() const
{
	return array.rbegin();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::const_reverse_iterator
fcppt::container::field<ArrayType>::rend() const
{
	return array.rend();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::vector const
fcppt::container::field<ArrayType>::position(
	const_iterator const it
) const
{
	difference_type const diff(
		std::distance(
			begin(),
			it
		)
	);

	return vector(
		diff % dimension().w(),
		diff / dimension().w()
	);
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::iterator
fcppt::container::field<ArrayType>::position_it(
	vector const &v
)
{
	return begin() + v.y() * dimension().w() + v.x();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::const_iterator
fcppt::container::field<ArrayType>::position_it(
	vector const &v
) const
{
	return begin() + v.y() * dimension().w() + v.x();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::allocator_type
fcppt::container::field<ArrayType>::get_allocator() const
{
	return array.get_allocator();
}

template<
	typename ArrayType
>
void
fcppt::container::field<ArrayType>::resize_canvas(
	dim const &n,
	const_reference value
)
{
	// dimension hasn't changed?
	if (dimension() == n)
		return;

	field new_(
		n,
		value
	);

	for (vector p = vector::null(); p.y() < std::min(n.h(),dimension().h()); ++p.y())
		for (p.x() = 0; p.x() < std::min(n.w(),dimension().h()); ++p.x())
			new_.pos(p) = pos(p);

	swap(
		new_
	);
}

template<
	typename ArrayType
>
void
fcppt::container::field<ArrayType>::resize(
	dim const &n,
	const_reference value
)
{
	if (dimension_ == n)
		return;

	dimension_ = n;

	array.resize(
		size(),
		value
	);
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::value_type &
fcppt::container::field<ArrayType>::pos(
	vector const &p
)
{
	range_check(p);

	return array[
		static_cast<size_type>(p.y() * dimension().w() + p.x())
	];
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::value_type const &
fcppt::container::field<ArrayType>::pos(
	vector const &p
) const
{
	range_check(p);

	return array[
		static_cast<size_type>(p.y() * dimension().w() + p.x())
	];
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::reference
fcppt::container::field<ArrayType>::front()
{
	return array.front();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::const_reference
fcppt::container::field<ArrayType>::front() const
{
	return array.front();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::reference
fcppt::container::field<ArrayType>::back()
{
	return array.back();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::const_reference
fcppt::container::field<ArrayType>::back() const
{
	return array.back();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::value_type
fcppt::container::field<ArrayType>::x(
	const_iterator const p
) const
{
	check_w();

	return std::distance(begin(), p) % dimension().w();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::value_type
fcppt::container::field<ArrayType>::y(
	const_iterator const p
) const
{
	check_w();

	return std::distance(begin(),p) / dimension().w();
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::vector const
fcppt::container::field<ArrayType>::pos(
	const_iterator const p
) const
{
	return vector(x(p), y(p));
}

template<
	typename ArrayType
>
typename fcppt::container::field<ArrayType>::dim const
fcppt::container::field<ArrayType>::dimension() const
{
	return dimension_;
}

template<
	typename ArrayType
>
void
fcppt::container::field<ArrayType>::range_check(
	vector const &v
) const
{
	FCPPT_ASSERT(v.x() < dimension().w() && v.y() < dimension().h());
}

template<
	typename ArrayType
>
void
fcppt::container::field<ArrayType>::check_w() const
{
	FCPPT_ASSERT(dimension().w() != 0);
}

template<
	typename ArrayType
>
bool
fcppt::container::operator==(
	field<ArrayType> const &l,
	field<ArrayType> const &r
)
{
	return
		l.dimension() == r.dimension()
		&& std::equal(l.begin(), l.end(), r.begin());
}

template<
	typename ArrayType
>
bool
fcppt::container::operator!=(
	field<ArrayType> const &l,
	field<ArrayType> const &r
)
{
	return !(l == r);
}

template<
	typename ArrayType,
	typename Ch,
	typename Traits
>
std::basic_ostream<Ch,Traits> &
fcppt::container::operator<<(
	std::basic_ostream<Ch,Traits> &stream,
	field<ArrayType> const &f
)
{
	typedef field<ArrayType> field_type;
	typedef typename field_type::size_type size_type;
	typedef typename field_type::vector vector;

	for (size_type y = 0; y < f.dimension().h(); ++y)
	{
		for (size_type x = 0; x < f.dimension().w(); ++x)
			stream << f.pos(vector(x,y)) << stream.widen(' ');
		stream << stream.widen('\n');
	}
	return stream;
}

#endif
