//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/variant/object_decl.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/invalid_get.hpp>
#include <fcppt/variant/detail/copy.hpp>
#include <fcppt/variant/detail/destroy.hpp>
#include <fcppt/variant/detail/construct.hpp>
#include <fcppt/variant/detail/type_info.hpp>
#include <fcppt/variant/detail/index_of.hpp>
#include <fcppt/variant/detail/real_type.hpp>
#include <fcppt/variant/detail/unwrap_recursive.hpp>
#include <fcppt/variant/detail/apply_unary_internal.hpp>
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
	U const &u
)
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

	data_ = detail::apply_unary_internal(
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
	U const &u
)
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
	object const &o
)
{
	if(o.empty())
	{
		destroy();
		return *this;
	}

	detail::apply_unary_internal(
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
	if(
		index_ != static_cast<
			size_type
		>(
			detail::index_of<
				Types,
				U
			>::value
		)
	)
		throw invalid_get();

	return
		detail::unwrap_recursive(
			get_raw<
				typename detail::real_type<
					Types,
					U
				>::type
			>()
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
	return
		const_cast<
			U &
		>(
			const_cast<
				object<Types> const *
			>(
				this
			)-> template get<
				U
			>()
		);
}

template<
	typename Types
>
template<
	typename U
>
U &
fcppt::variant::object<Types>::get_raw()
{
	return
		*static_cast<
			U *
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
U const &
fcppt::variant::object<Types>::get_raw() const
{
	return
		*static_cast<
			U const *
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
fcppt::variant::object<Types>::construct(
	U const &u
)
{
	data_ =
		new (
			storage_.data()
		)
		typename detail::real_type<
			Types,
			U
		>::type(
			u
		);

	size_type const new_index(
		detail::index_of<
			Types,
			U
		>::value
	);

	BOOST_STATIC_ASSERT(
		new_index < elements
	);

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

	detail::apply_unary_internal(
		detail::destroy(),
		*this
	);

	index_ = elements;
	data_ = 0;
}

#endif
