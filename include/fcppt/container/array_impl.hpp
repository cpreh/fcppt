//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_IMPL_HPP_INCLUDED

#include <fcppt/container/array_decl.hpp>
#include <fcppt/container/detail/array_range_check.hpp>
#include <fcppt/container/detail/array_swap.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	std::size_t N
>
void
fcppt::container::array<T, N>::fill(
	T const &_value
)
{
	std::fill(
		begin(),
		end(),
		_value
	);
}

template<
	typename T,
	std::size_t N
>
void
fcppt::container::array<T, N>::swap(
	array<T, N> &_other
)
{
	container::detail::array_swap(
		*this,
		_other
	);
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::iterator
fcppt::container::array<T, N>::begin()
{
	return elem_;
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_iterator
fcppt::container::array<T, N>::begin() const
{
	return elem_;
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::iterator
fcppt::container::array<T, N>::end()
{
	return elem_ + N;
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_iterator
fcppt::container::array<T, N>::end() const
{
	return elem_ + N;
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::reverse_iterator
fcppt::container::array<T, N>::rbegin()
{
	return reverse_iterator(end());
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_reverse_iterator
fcppt::container::array<T, N>::rbegin() const
{
	return const_reverse_iterator(end());
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::reverse_iterator
fcppt::container::array<T, N>::rend()
{
	return reverse_iterator(begin());
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_reverse_iterator
fcppt::container::array<T, N>::rend() const
{
	return const_reverse_iterator(begin());
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_iterator
fcppt::container::array<T, N>::cbegin() const
{
	return begin();
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_iterator
fcppt::container::array<T, N>::cend() const
{
	return end();
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_reverse_iterator
fcppt::container::array<T, N>::crbegin() const
{
	return rbegin();
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_reverse_iterator
fcppt::container::array<T, N>::crend() const
{
	return rend();
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::size_type
fcppt::container::array<T, N>::size() const
{
	return N;
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::size_type
fcppt::container::array<T, N>::max_size() const
{
	return size();
}

template<
	typename T,
	std::size_t N
>
bool
fcppt::container::array<T, N>::empty() const
{
	return N == 0;
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::reference
fcppt::container::array<T, N>::operator[](
	size_type const _index
)
{
	return elem_[_index];
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_reference
fcppt::container::array<T, N>::operator[](
	size_type const _index
) const
{
	return elem_[_index];
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::reference
fcppt::container::array<T, N>::at(
	size_type const _index
)
{
	container::detail::array_range_check<
		N
	>(
		_index
	);

	return (*this)[_index];
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_reference
fcppt::container::array<T, N>::at(
	size_type const _index
) const
{
	container::detail::array_range_check<
		N
	>(
		_index
	);

	return (*this)[_index];
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::reference
fcppt::container::array<T, N>::front()
{
	return *begin();
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_reference
fcppt::container::array<T, N>::front() const
{
	return *begin();
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::reference
fcppt::container::array<T, N>::back()
{
	return *std::prev(end());
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_reference
fcppt::container::array<T, N>::back() const
{
	return *std::prev(end());
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::pointer
fcppt::container::array<T, N>::data()
{
	return elem_;
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_pointer
fcppt::container::array<T, N>::data() const
{
	return elem_;
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::pointer
fcppt::container::array<T, N>::data_end()
{
	return elem_ + N;
}

template<
	typename T,
	std::size_t N
>
typename fcppt::container::array<T, N>::const_pointer
fcppt::container::array<T, N>::data_end() const
{
	return elem_ + N;
}

#endif
