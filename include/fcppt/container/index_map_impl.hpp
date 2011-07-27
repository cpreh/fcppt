//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_INDEX_MAP_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_INDEX_MAP_IMPL_HPP_INCLUDED

#include <fcppt/container/index_map_decl.hpp>

template<
	typename T,
	typename A
>
typename fcppt::container::index_map<T, A>::reference
fcppt::container::index_map<T, A>::operator[](
	size_type const _index
)
{
	return
		(*this).get_default(
			_index,
			T()
		);
}

template<
	typename T,
	typename A
>
typename fcppt::container::index_map<T, A>::reference
fcppt::container::index_map<T, A>::get_default(
	size_type const _index,
	const_reference _ref
)
{
	if(
		_index >= size()
	)
		impl_.resize(
			_index + 1u,
			_ref
		);

	return
		impl_[
			_index
		];
}

template<
	typename T,
	typename A
>
typename fcppt::container::index_map<T, A>::size_type
fcppt::container::index_map<T, A>::size() const
{
	return impl_.size();
}

#endif
