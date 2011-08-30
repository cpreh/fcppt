//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_DECL_HPP_INCLUDED

#include <fcppt/container/detail/array_storage.hpp>
#include <fcppt/container/array_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{

template<
	typename T,
	std::size_t N
>
struct array
{
	typedef T &reference;

	typedef T const &const_reference;

	typedef T *iterator;

	typedef T const *const_iterator;

	typedef std::size_t size_type;

	typedef std::ptrdiff_t difference_type;

	typedef T value_type;

	typedef T *pointer;

	typedef T const *const_pointer;

	typedef std::reverse_iterator<iterator> reverse_iterator;

	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	// for boost::array compatibility
	enum
	{
		static_size = N
	};

	typename detail::array_storage<
		T,
		N
	>::type elem_;

	void
	fill(
		T const &
	);

	void
	swap(
		array<T, N> &
	);

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

	size_type
	size() const;

	size_type
	max_size() const;

	bool
	empty() const;

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

	// Additional functions to std::array
	pointer
	data();

	const_pointer
	data() const;

	pointer
	data_end();

	const_pointer
	data_end() const;
};

}
}

#endif
