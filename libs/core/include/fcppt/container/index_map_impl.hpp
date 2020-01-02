//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_INDEX_MAP_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_INDEX_MAP_IMPL_HPP_INCLUDED

#include <fcppt/function_impl.hpp>
#include <fcppt/container/index_map_decl.hpp>


template<
	typename T,
	typename A
>
fcppt::container::index_map<
	T,
	A
>::index_map()
:
	impl_()
{
}

template<
	typename T,
	typename A
>
typename
fcppt::container::index_map<
	T,
	A
>::reference
fcppt::container::index_map<
	T,
	A
>::get(
	size_type const _index,
	insert_function const _insert
)
{
	if(
		_index
		>=
		impl_.size()
	)
	{
		size_type const needed_size{
			_index
			+
			1u
		};

		impl_.reserve(
			needed_size
		);

		while(
			impl_.size()
			<
			needed_size
		)
			impl_.push_back(
				_insert()
			);
	}

	return
		impl_[
			_index
		];
}

template<
	typename T,
	typename A
>
typename
fcppt::container::index_map<
	T,
	A
>::reference
fcppt::container::index_map<
	T,
	A
>::operator[](
	size_type const _index
)
{
	return
		this->get(
			_index,
			insert_function{
				[]{
					return
						T();
				}
			}
		);
}

template<
	typename T,
	typename A
>
typename
fcppt::container::index_map<
	T,
	A
>::internal_type const &
fcppt::container::index_map<
	T,
	A
>::impl() const
{
	return
		impl_;
}

#endif
