//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_MAP_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_MAP_IMPL_HPP_INCLUDED

#include <fcppt/container/map_decl.hpp>
#include <fcppt/container/insert_failed.hpp>
#include <fcppt/container/not_found.hpp>
#include <fcppt/text.hpp>
#include <fcppt/type_name.hpp>
#include <typeinfo>
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
void
fcppt::container::map<
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
typename fcppt::container::map<
	MapType
>::iterator
fcppt::container::map<
	MapType
>::insert(
	iterator const p,
	value_type const &v
)
{
	size_type const old_size(
		size()
	);

	iterator const ret(
		impl_.insert(
			p,
			v
		)
	);

	if(
		size() == old_size
	)
		throw insert_failed(
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
	value_type const &v
)
{
	if(
		!impl_.insert(v).second
	)
		throw insert_failed(
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
	key_type const &k
)
{
	if(
		!impl_.erase(
			k
		)
	)
		throw not_found(
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
	key_type const &k)
{
	return 
		impl_.lower_bound(
			k);
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
	key_type const &k) const
{
	return 
		impl_.lower_bound(
			k);
}

template<
	typename MapType
>
fcppt::string const
fcppt::container::map<
	MapType
>::format_error(
	fcppt::string const &function_
)
{
	return
		type_name(
			typeid(
				map<
					MapType
				>
			)
		)
		+ FCPPT_TEXT("::")
		+ function_
		+ FCPPT_TEXT(" failed!");
}

#endif
