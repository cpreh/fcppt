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


#ifndef FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/variant/object_decl.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/invalid_get.hpp>
#include <fcppt/variant/detail/copy.hpp>
#include <fcppt/variant/detail/destroy.hpp>
#include <fcppt/variant/detail/construct.hpp>
#include <fcppt/variant/detail/type_info.hpp>
#include <fcppt/mpl/index_of.hpp>
#include <boost/static_assert.hpp>

template<
	typename Types
>
fcppt::variant::object<Types>::object()
:
	storage_(),
	index_(elements),
	data_(0)
{}

template<
	typename Types
>
template<
	typename U
>
fcppt::variant::object<Types>::object(
	U const &u)
:
	storage_(),
	index_(),
	data_()
{
	construct(
		u
	);
}

template<
	typename Types
>
fcppt::variant::object<Types>::object(
	object const &o
)
:
	storage_(),
	index_(o.index_),
	data_(0)
{
	if(o.empty())
		return;

	data_ = variant::apply_unary(
		detail::copy(
			storage_.data()
		),
		o
	);
}

template<
	typename Types
>
template<
	typename U
>
fcppt::variant::object<Types> &
fcppt::variant::object<Types>::operator=(
	U const &u)
{
	destroy();

	construct(
		u
	);

	return *this;
}

template<
	typename Types
>
fcppt::variant::object<Types> &
fcppt::variant::object<Types>::operator=(
	object const &o)
{
	if(o.empty())
	{
		destroy();
		return *this;
	}

	variant::apply_unary(
		detail::construct<
			object<
				Types
			>
		>(
			*this
		),
		o
	);

	return *this;
}

template<
	typename Types
>
fcppt::variant::object<Types>::~object()
{
	destroy();
}

template<
	typename Types
>
bool
fcppt::variant::object<Types>::empty() const
{
	return index_ == elements;
}

template<
	typename Types
>
template<
	typename U
>
U const &
fcppt::variant::object<Types>::get() const
{
	check_get<U>();

	return *static_cast<
		U const *
	>(
		data_
	);
}

template<
	typename Types
>
template<
	typename U
>
U &
fcppt::variant::object<Types>::get()
{
	check_get<U>();

	return *static_cast<
		U *
	>(
		data_
	);
}

template<
	typename Types
>
std::type_info const &
fcppt::variant::object<Types>::type() const
{
	return apply_unary(
		detail::type_info(),
		*this
	);
}

template<
	typename Types
>
fcppt::variant::size_type
fcppt::variant::object<Types>::type_index() const
{
	return index_;
}

template<
	typename Types
>
template<
	typename U
>
void
fcppt::variant::object<Types>::check_get() const
{
	if(
		index_ != static_cast<
			size_type
		>(
			mpl::index_of<Types, U>::value
		)
	)
		throw invalid_get();
}

template<
	typename Types
>
template<
	typename U
>
void
fcppt::variant::object<Types>::construct(
	U const &u)
{
	data_ = new (storage_.data()) U(u);

	size_type const new_index(
		mpl::index_of<
			Types,
			U
		>::value
	);

	BOOST_STATIC_ASSERT(new_index < elements);

	index_ = new_index;
}

template<
	typename Types
>
void
fcppt::variant::object<Types>::destroy()
{
	if(empty())
		return;

	variant::apply_unary(
		detail::destroy(),
		*this
	);

	index_ = elements;
	data_ = 0;
}

#endif
