//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_MAP_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_MAP_IMPL_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/type_name.hpp>
#include <fcppt/container/insert_failed.hpp>
#include <fcppt/container/map_decl.hpp>
#include <fcppt/container/not_found.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeinfo>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename MapType
>
fcppt::container::map<
	MapType
>::map()
:
	impl_()
{}

template<
	typename MapType
>
fcppt::container::map<
	MapType
>::map(
	map_type const &_impl
)
:
	impl_(_impl)
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
	In const _begin,
	In const _end
)
:
	impl_(
		_begin,
		_end
	)
{}

template<
	typename MapType
>
void
fcppt::container::map<
	MapType
>::insert(
	key_type const &_key,
	mapped_type const &_mapped
)
{
	insert(
		std::make_pair(
			_key,
			_mapped
		)
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
>::insert(
	iterator const _position,
	value_type const &_value
)
{
	size_type const old_size(
		size()
	);

	iterator const ret(
		impl_.insert(
			_position,
			_value
		)
	);

	if(
		size() == old_size
	)
		throw container::insert_failed(
			format_error(
				FCPPT_TEXT("insert")
			)
		);

	return ret;
}

template<
	typename MapType
>
void
fcppt::container::map<
	MapType
>::insert(
	value_type const &_value
)
{
	if(
		!impl_.insert(_value).second
	)
		throw container::insert_failed(
			format_error(
				FCPPT_TEXT("insert")
			)
		);
}

template<
	typename MapType
>
void
fcppt::container::map<
	MapType
>::erase(
	key_type const &_key
)
{
	if(
		!impl_.erase(
			_key
		)
	)
		throw container::not_found(
			format_error(
				FCPPT_TEXT("erase")
			)
		);
}

template<
	typename MapType
>
void
fcppt::container::map<
	MapType
>::erase(
	iterator const _position
)
{
	impl_.erase(
		_position
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
	key_type const &_key
)
{
	return impl_.find(_key);
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
	key_type const &_key
) const
{
	return impl_.find(_key);
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
	key_type const &_key
) const
{
	typename map_type::const_iterator const it(
		impl_.find(
			_key
		)
	);

	if(
		it == impl_.end()
	)
		throw container::not_found(
			format_error(
				FCPPT_TEXT("operator[]")
			)
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
	key_type const &_key
)
{
	return
		const_cast<
			mapped_type &
		>(
			const_cast<
				map const &
			>(
				*this
			)[
				_key
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
	key_type const &_key
) const
{
	return impl_.find(_key) != impl_.end();
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

template<
	typename MapType
>
typename
fcppt::container::map<
	MapType
>::iterator
fcppt::container::map<
	MapType
>::lower_bound(
	key_type const &_key
)
{
	return
		impl_.lower_bound(
			_key
		);
}

template<
	typename MapType
>
typename
fcppt::container::map<
	MapType
>::const_iterator
fcppt::container::map<
	MapType
>::lower_bound(
	key_type const &_key
) const
{
	return
		impl_.lower_bound(
			_key
		);
}

template<
	typename MapType
>
fcppt::string const
fcppt::container::map<
	MapType
>::format_error(
	fcppt::string const &_function
)
{
	return
		fcppt::type_name(
			typeid(
				map<
					MapType
				>
			)
		)
		+ FCPPT_TEXT("::")
		+ _function
		+ FCPPT_TEXT(" failed!");
}

#endif
