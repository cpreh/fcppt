//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/container/grid/object_decl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/assert.hpp>
#include <boost/next_prior.hpp>
#include <boost/foreach.hpp>
#include <algorithm>
#include <iterator>
#include <functional>
#include <ostream>

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
fcppt::container::grid::object<ArrayType,N>::object(
	allocator_type const &alloc
)
:
	dimension_(
		dim::null()),
	array_(
		alloc)
{}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
fcppt::container::grid::object<ArrayType,N>::object(
	object const &r
)
:
	dimension_(
		r.dimension_),
	array_(
		r.array_)
{}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
fcppt::container::grid::object<ArrayType,N>::object(
	dim const &dimension_,
	value_type const &t,
	allocator_type const &alloc
)
:
	dimension_(
		dimension_),
	array_(
		size(),
		t,
		alloc
	)
{}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
template<
	typename Iterator
>
fcppt::container::grid::object<ArrayType,N>::object(
	dim const &dimension_,
	Iterator const b,
	Iterator const e,
	allocator_type const &alloc
)
:
	dimension_(
		dimension_),
	array_(
		alloc)
{
	array_.resize(
		size()
	);

	std::copy(
		b, 
		e, 
		begin());
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
void
fcppt::container::grid::object<ArrayType,N>::swap(
	grid::object<ArrayType,N> &r
)
{
	std::swap(
		dimension_,
		r.dimension_
	);

	array_.swap(
		r.array_
	);
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
fcppt::container::grid::object<ArrayType,N> &
fcppt::container::grid::object<ArrayType,N>::operator=(
	grid::object<ArrayType,N> const &r
)
{
	if(&r != this)
	{
		dimension_ = r.dimension_;
		array_ = r.array_;
	}

	return *this;
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::size_type
fcppt::container::grid::object<ArrayType,N>::size() const
{
	return dimension_.content();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::size_type
fcppt::container::grid::object<ArrayType,N>::max_size() const
{
	return array_.max_size();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
bool
fcppt::container::grid::object<ArrayType,N>::empty() const
{
	return array_.empty();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::iterator
fcppt::container::grid::object<ArrayType,N>::begin()
{
	return array_.begin();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::iterator
fcppt::container::grid::object<ArrayType,N>::end()
{
	return array_.end();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::const_iterator
fcppt::container::grid::object<ArrayType,N>::begin() const
{
	return array_.begin();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::const_iterator
fcppt::container::grid::object<ArrayType,N>::end() const
{
	return array_.end();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::reverse_iterator
fcppt::container::grid::object<ArrayType,N>::rbegin()
{
	return array_.rbegin();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::reverse_iterator
fcppt::container::grid::object<ArrayType,N>::rend()
{
	return array_.rend();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::const_reverse_iterator
fcppt::container::grid::object<ArrayType,N>::rbegin() const
{
	return array_.rbegin();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::const_reverse_iterator
fcppt::container::grid::object<ArrayType,N>::rend() const
{
	return array_.rend();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::const_iterator
fcppt::container::grid::object<ArrayType,N>::cbegin() const
{
	return begin();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::const_iterator
fcppt::container::grid::object<ArrayType,N>::cend() const
{
	return end();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::const_reverse_iterator
fcppt::container::grid::object<ArrayType,N>::crbegin() const
{
	return rbegin();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::const_reverse_iterator
fcppt::container::grid::object<ArrayType,N>::crend() const
{
	return rend();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::allocator_type
fcppt::container::grid::object<ArrayType,N>::get_allocator() const
{
	return array_.get_allocator();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
void
fcppt::container::grid::object<ArrayType,N>::resize_plain(
	dim const &n,
	const_reference value
)
{
	if (dimension_ == n)
		return;

	dimension_ = n;

	array_.resize(
		size(),
		value
	);
}

// TODO: Implement resize down here
template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
void
fcppt::container::grid::object<ArrayType,N>::resize(
	dim const &n,
	const_reference value
)
{
	if (dimension_ == n)
		return;
	
	object ng(
		n,
		value);
	
	copy_layer(
		ng,
		cbegin(),
		cend(),
		ng.begin(),
		static_cast<size_type>(
			N-1));

	this->swap(
		ng);
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::value_type &
fcppt::container::grid::object<ArrayType,N>::pos(
	vector const &p
)
{
	return 
		const_cast<value_type &>(
			const_cast<object const &>(*this).pos(
				p));
}

#include <iostream>

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::value_type const &
fcppt::container::grid::object<ArrayType,N>::pos(
	vector const &p
) const
{
	std::cerr << "in pos \n";
	range_check(
		p);
	std::cerr << "after range check\n";

	size_type result = 
		static_cast<size_type>(
			0);

	for (size_type i = 0; i < N; ++i)
	{
		std::cerr << "point, first coordinate: " << p[i] << "\n";
		std::cerr << "end\n";
		std::cerr << "next: " << (*boost::next(dimension().begin(),i+1)) << "\n";
		result += 
			p[i] * 
			std::accumulate(
				dimension().begin(),
				boost::next(
					dimension().begin(),
					i),
				static_cast<value_type>(
					1),
				std::multiplies<size_type>());
		std::cerr << "second try\n";
	}

	std::cerr << "result index: " << result << "\n";

	return array_[result];
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::reference
fcppt::container::grid::object<ArrayType,N>::front()
{
	return array_.front();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::const_reference
fcppt::container::grid::object<ArrayType,N>::front() const
{
	return array_.front();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::reference
fcppt::container::grid::object<ArrayType,N>::back()
{
	return array_.back();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::const_reference
fcppt::container::grid::object<ArrayType,N>::back() const
{
	return array_.back();
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
typename fcppt::container::grid::object<ArrayType,N>::dim const &
fcppt::container::grid::object<ArrayType,N>::dimension() const
{
	return dimension_;
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
void
fcppt::container::grid::object<ArrayType,N>::range_check(
	vector const &v
) const
{
	for (size_type i = 0; i < N; ++i)
	{
		FCPPT_ASSERT(
			v[i] < dimension()[i]);
	}
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
void
fcppt::container::grid::object<ArrayType,N>::copy_layer(
	object &dest_grid,
	const_iterator src,
	const_iterator const src_end,
	iterator dest,
	size_type const d)
{
	size_type const 
		src_increment = 
			std::accumulate(
				dimension().begin(),
				boost::next(
					dimension().begin(),
					d),
				static_cast<size_type>(1),
				std::multiplies<size_type>()),
		dest_increment = 
			std::accumulate(
				dest_grid.dimension().begin(),
				boost::next(
					dest_grid.dimension().begin(),
					d),
				static_cast<size_type>(1),
				std::multiplies<size_type>());

	for(
		;
		src != src_end;
		src = 
			boost::next(
				src,
				src_increment))
	{
		if (d == static_cast<size_type>(1))
		{
			std::copy(
				src,
				boost::next(
					src,
					src_increment),
				dest);
		}
		else
		{
			copy_layer(
				dest_grid,
				src,
				boost::next(
					src,
					src_increment),
				dest,
				static_cast<size_type>(
					d-1));
		}
		dest = 
			boost::next(
				dest,
				dest_increment);
	}
}


template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
void
fcppt::container::grid::swap(
	grid::object<ArrayType,N> &a,
	grid::object<ArrayType,N> &b
)
{
	a.swap(
		b);
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
bool
fcppt::container::grid::operator==(
	grid::object<ArrayType,N> const &l,
	grid::object<ArrayType,N> const &r
)
{
	return
		l.dimension() == r.dimension()
		&& std::equal(l.begin(), l.end(), r.begin());
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N
>
bool
fcppt::container::grid::operator!=(
	grid::object<ArrayType,N> const &l,
	grid::object<ArrayType,N> const &r
)
{
	return !(l == r);
}

template<
	typename ArrayType,
	fcppt::container::grid::size_type N,
	typename Ch,
	typename Traits
>
std::basic_ostream<Ch,Traits> &
fcppt::container::grid::operator<<(
	std::basic_ostream<Ch,Traits> &stream,
	grid::object<ArrayType,N> const &f
)
{
	/*
	// FIXME
	typedef grid::object<ArrayType,N> grid_type;
	typedef typename grid_type::size_type size_type;
	typedef typename grid_type::vector vector;

	for (size_type y = 0; y < f.dimension().h(); ++y)
	{
		for (size_type x = 0; x < f.dimension().w(); ++x)
			stream << f.pos(vector(x,y)) << stream.widen(' ');
		stream << stream.widen('\n');
	}
	*/
	return stream;
}

#endif
