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


#ifndef FCPPT_CONTAINER_MAP_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_MAP_IMPL_HPP_INCLUDED

#include <fcppt/container/map_decl.hpp>
#include <fcppt/container/insert_failed.hpp>
#include <fcppt/container/not_found.hpp>
#include <fcppt/text.hpp>
#include <utility>

template<
	typename MapType
>
fcppt::container::map<
	MapType
>::map()
{}

template<
	typename MapType
>
fcppt::container::map<
	MapType
>::map(
	map_type const &impl_
)
:
	impl_(impl_)
{}

template<
	typename MapType
>
template<
	typename In
>
fcppt::container::map<
	MapType
>::map(
	In const beg,
	In const end
)
:
	impl_(
		beg,
		end)
{}

template<
	typename MapType
>
void fcppt::container::map<
	MapType
>::insert(
	key_type const &k,
	mapped_type const &m
)
{
	insert(
		std::make_pair(
			k,
			m
		)
	);
}

template<
	typename MapType
>
void fcppt::container::map<
	MapType
>::insert(
	value_type const &v
)
{
	if(
		!impl_.insert(v).second
	)
		throw insert_failed(
			FCPPT_TEXT("insert in map failed!")
		);
}

template<
	typename MapType
>
void fcppt::container::map<
	MapType
>::erase(
	key_type const &k
)
{
	if(
		!impl_.erase(
			k
		)
	)
		throw not_found(
			FCPPT_TEXT("erase from map failed!")
		);
}

template<
	typename MapType
>
void fcppt::container::map<
	MapType
>::erase(
	iterator const it
)
{
	impl_.erase(
		it
	);
}

template<
	typename MapType
>
typename fcppt::container::map<
	MapType
>::iterator
fcppt::container::map<
	MapType
>::find(
	key_type const &k
)
{
	return impl_.find(k);
}

template<
	typename MapType
>
typename fcppt::container::map<
	MapType
>::const_iterator
fcppt::container::map<
	MapType
>::find(
	key_type const &k
) const
{
	return impl_.find(k);
}

template<
	typename MapType
>
typename fcppt::container::map<
	MapType
>::mapped_type const &
fcppt::container::map<
	MapType
>::operator[](
	key_type const &k
) const
{
	typename map_type::const_iterator const it(
		impl_.find(k)
	);

	if(
		it == impl_.end()
	)
		throw not_found(
			FCPPT_TEXT("operator[] of map failed!")
		);

	return it->second;
}

template<
	typename MapType
>
typename fcppt::container::map<
	MapType
>::mapped_type &
fcppt::container::map<
	MapType
>::operator[](
	key_type const &k
)
{
	return const_cast<
		mapped_type &
	>(
		const_cast<
			map const &
		>(
			*this
		)[
			k
		]
	);
}

template<
	typename MapType
>
bool
fcppt::container::map<
	MapType
>::contains(
	key_type const &key
) const
{
	return impl_.find(key) != impl_.end();
}

template<
	typename MapType
>
typename fcppt::container::map<
	MapType
>::iterator
fcppt::container::map<
	MapType
>::begin()
{
	return impl_.begin();
}

template<
	typename MapType
>
typename fcppt::container::map<
	MapType
>::const_iterator
fcppt::container::map<
	MapType
>::begin() const
{
	return impl_.begin();
}

template<
	typename MapType
>
typename fcppt::container::map<
	MapType
>::iterator
fcppt::container::map<
	MapType
>::end()
{
	return impl_.end();
}

template<
	typename MapType
>
typename fcppt::container::map<
	MapType
>::const_iterator
fcppt::container::map<
	MapType
>::end() const
{
	return impl_.end();
}

template<
	typename MapType
>
typename fcppt::container::map<
	MapType
>::size_type
fcppt::container::map<
	MapType
>::size() const
{
	return impl_.size();
}

template<
	typename MapType
>
bool
fcppt::container::map<
	MapType
>::empty() const
{
	return begin() == end();
}

#endif
