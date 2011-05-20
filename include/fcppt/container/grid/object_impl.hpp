//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/container/grid/object_decl.hpp>
#include <fcppt/container/grid/detail/access_member.hpp>
#include <fcppt/container/grid/detail/at.hpp>
#include <fcppt/container/grid/detail/data.hpp>
#include <fcppt/container/grid/detail/data_end.hpp>
#include <fcppt/container/grid/detail/resize.hpp>
#include <fcppt/container/grid/detail/shrink_to_fit.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<T, N, A>::object()
:
	container_(),
	size_(
		dim::null()
	)
{
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<T, N, A>::object(
	dim const &_size
)
:
	container_(
		_size.content()
	),
	size_(_size)
{
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<T, N, A>::object(
	dim const &_size,
	const_reference _value
)
:
	container_(
		_size.content(),
		_value
	),
	size_(_size)
{
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
template<
	typename In
>
fcppt::container::grid::object<T, N, A>::object(
	dim const &_size,
	In const _begin,
	In const _end
)
:
	container_(
		_begin,
		_end
	),
	size_(_size)
{
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<T, N, A>::object(
	object const &_other
)
:
	container_(
		_other.container_
	),
	size_(
		_other.size_
	)
{}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<T, N, A> &
fcppt::container::grid::object<T, N, A>::operator=(
	object const &_other
)
{
	if(
		&_other == this
	)
		return *this;

	container_ = _other.container_;

	size_ = _other.size_;

	return *this;
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<T, N, A>::~object()
{
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::reference
fcppt::container::grid::object<T, N, A>::operator[](
	dim const &_pos
)
{
	return
		detail::access_member(
			container_,
			size_,
			_pos
		);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::const_reference
fcppt::container::grid::object<T, N, A>::operator[](
	dim const &_pos
) const
{
	return
		detail::access_member(
			container_,
			size_,
			_pos
		);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::reference
fcppt::container::grid::object<T, N, A>::at(
	dim const &_pos
)
{
	return
		detail::at(
			*this,
			size_,
			_pos
		);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::const_reference
fcppt::container::grid::object<T, N, A>::at(
	dim const &_pos
) const
{
	return
		detail::at(
			*this,
			size_,
			_pos
		);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::dim const &
fcppt::container::grid::object<T, N, A>::size() const
{
	return size_;
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::size_type
fcppt::container::grid::object<T, N, A>::content() const
{
	return size_.content();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
void
fcppt::container::grid::object<T, N, A>::resize(
	dim const &_size
)
{
	detail::resize(
		container_,
		_size
	);

	size_ = _size;
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
void
fcppt::container::grid::object<T, N, A>::shrink_to_fit()
{
	detail::shrink_to_fit(
		container_
	);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::pointer
fcppt::container::grid::object<T, N, A>::data()
{
	return
		detail::data(
			container_
		);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::const_pointer
fcppt::container::grid::object<T, N, A>::data() const
{
	return
		detail::data(
			container_
		);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::pointer
fcppt::container::grid::object<T, N, A>::data_end()
{
	return
		detail::data_end(
			container_
		);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::const_pointer
fcppt::container::grid::object<T, N, A>::data_end() const
{
	return
		detail::data_end(
			container_
		);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::iterator
fcppt::container::grid::object<T, N, A>::begin()
{
	return container_.begin();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::const_iterator
fcppt::container::grid::object<T, N, A>::begin() const
{
	return container_.begin();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::const_iterator
fcppt::container::grid::object<T, N, A>::cbegin() const
{
	return container_.begin();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::iterator
fcppt::container::grid::object<T, N, A>::end()
{
	return container_.end();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::const_iterator
fcppt::container::grid::object<T, N, A>::end() const
{
	return container_.end();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::const_iterator
fcppt::container::grid::object<T, N, A>::cend() const
{
	return container_.end();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::reverse_iterator
fcppt::container::grid::object<T, N, A>::rbegin()
{
	return container_.rbegin();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::const_reverse_iterator
fcppt::container::grid::object<T, N, A>::rbegin() const
{
	return container_.rend();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::const_reverse_iterator
fcppt::container::grid::object<T, N, A>::crbegin() const
{
	return container_.rbegin();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::reverse_iterator
fcppt::container::grid::object<T, N, A>::rend()
{
	return container_.rend();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::const_reverse_iterator
fcppt::container::grid::object<T, N, A>::rend() const
{
	return container_.rend();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<T, N, A>::const_reverse_iterator
fcppt::container::grid::object<T, N, A>::crend() const
{
	return container_.rend();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
void
fcppt::container::grid::object<T, N, A>::swap(
	object &_other
)
{
	container_.swap(
		_other.container_
	);

	size_.swap(
		_other.size_
	);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
void
fcppt::container::grid::swap(
	object<T, N, A> &_a,
	object<T, N, A> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
