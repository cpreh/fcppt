//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_decl.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/variant/detail/apply_unary_internal.hpp>
#include <fcppt/variant/detail/assert_type.hpp>
#include <fcppt/variant/detail/assign_object.hpp>
#include <fcppt/variant/detail/assign_value.hpp>
#include <fcppt/variant/detail/construct.hpp>
#include <fcppt/variant/detail/copy.hpp>
#include <fcppt/variant/detail/destroy.hpp>
#include <fcppt/variant/detail/get_impl.hpp>
#include <fcppt/variant/detail/index_of.hpp>
#include <fcppt/variant/detail/real_type.hpp>
#include <fcppt/variant/detail/type_info.hpp>
#include <fcppt/config/external_begin.hpp>
#include <new>
#include <fcppt/config/external_end.hpp>


template<
	typename Types
>
template<
	typename U
>
fcppt::variant::object<Types>::object(
	U const &_other
)
:
	storage_(),
	index_(),
	data_()
{
	this->construct(
		_other
	);
}

template<
	typename Types
>
fcppt::variant::object<Types>::object(
	object const &_other
)
:
	storage_(),
	index_(
		_other.index_
	),
	data_(
		detail::apply_unary_internal(
			detail::copy(
				storage_.data()
			),
			_other
		)
	)
{
}

template<
	typename Types
>
template<
	typename U
>
fcppt::variant::object<Types> &
fcppt::variant::object<Types>::operator=(
	U const &_other
)
{
	if(
		detail::index_of<
			Types,
			U
		>::value
		==
		index_
	)
		detail::apply_unary_internal(
			detail::assign_value<
				U
			>(
				_other
			),
			*this
		);
	else
	{
		this->destroy();

		this->construct(
			_other
		);
	}

	return *this;
}

template<
	typename Types
>
fcppt::variant::object<Types> &
fcppt::variant::object<Types>::operator=(
	object const &_other
)
{
	if(
		index_
		== _other.type_index()
	)
		detail::apply_unary_internal(
			detail::assign_object<
				variant::object<
					Types
				>
			>(
				*this
			),
			_other
		);
	else
		detail::apply_unary_internal(
			detail::construct<
				variant::object<
					Types
				>
			>(
				*this
			),
			_other
		);

	return *this;
}

template<
	typename Types
>
fcppt::variant::object<Types>::~object()
{
	this->destroy();
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
	FCPPT_VARIANT_DETAIL_ASSERT_TYPE(
		Types,
		U,
		elements
	);

	return
		detail::get_impl<
			U const
		>(
			*this
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
	FCPPT_VARIANT_DETAIL_ASSERT_TYPE(
		Types,
		U,
		elements
	);

	return
		detail::get_impl<
			U
		>(
			*this
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
	FCPPT_VARIANT_DETAIL_ASSERT_TYPE(
		Types,
		U,
		elements
	);

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
	FCPPT_VARIANT_DETAIL_ASSERT_TYPE(
		Types,
		U,
		elements
	);

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
	return
		variant::apply_unary(
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
	U const &_other
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
			_other
		);

	FCPPT_VARIANT_DETAIL_ASSERT_TYPE(
		Types,
		U,
		elements
	);

	index_ =
		detail::index_of<
			Types,
			U
		>::value;
}

template<
	typename Types
>
void
fcppt::variant::object<Types>::destroy()
{
	detail::apply_unary_internal(
		detail::destroy(),
		*this
	);
}

#endif
