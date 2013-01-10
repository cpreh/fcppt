//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
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


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Types
>
template<
	typename U
>
fcppt::variant::object<
	Types
>::object(
	U const &_other
)
:
	storage_()
	// Don't initialize index_
{
	this->construct(
		_other
	);
}

FCPPT_PP_POP_WARNING

template<
	typename Types
>
fcppt::variant::object<
	Types
>::object(
	object const &_other
)
:
	storage_(),
	index_(
		_other.index_
	)
{
	fcppt::variant::detail::apply_unary_internal(
		fcppt::variant::detail::copy(
			this->raw_data()
		),
		_other
	);
}

template<
	typename Types
>
template<
	typename U
>
fcppt::variant::object<
	Types
> &
fcppt::variant::object<
	Types
>::operator=(
	U const &_other
)
{
	if(
		fcppt::variant::detail::index_of<
			Types,
			U
		>::value
		==
		index_
	)
		fcppt::variant::detail::apply_unary_internal(
			fcppt::variant::detail::assign_value<
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
fcppt::variant::object<
	Types
> &
fcppt::variant::object<
	Types
>::operator=(
	object const &_other
)
{
	if(
		index_
		==
		_other.type_index()
	)
		fcppt::variant::detail::apply_unary_internal(
			fcppt::variant::detail::assign_object<
				fcppt::variant::object<
					Types
				>
			>(
				*this
			),
			_other
		);
	else
		fcppt::variant::detail::apply_unary_internal(
			fcppt::variant::detail::construct<
				fcppt::variant::object<
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
fcppt::variant::object<
	Types
>::~object()
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
fcppt::variant::object<
	Types
>::get() const
{
	FCPPT_VARIANT_DETAIL_ASSERT_TYPE(
		Types,
		U,
		elements
	);

	return
		fcppt::variant::detail::get_impl<
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
fcppt::variant::object<
	Types
>::get()
{
	FCPPT_VARIANT_DETAIL_ASSERT_TYPE(
		Types,
		U,
		elements
	);

	return
		fcppt::variant::detail::get_impl<
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
fcppt::variant::object<
	Types
>::get_raw()
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
			this->raw_data()
		);
}

template<
	typename Types
>
template<
	typename U
>
U const &
fcppt::variant::object<
	Types
>::get_raw() const
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
			this->raw_data()
		);
}

template<
	typename Types
>
std::type_info const &
fcppt::variant::object<
	Types
>::type() const
{
	return
		fcppt::variant::apply_unary(
			fcppt::variant::detail::type_info(),
			*this
		);
}

template<
	typename Types
>
fcppt::variant::size_type
fcppt::variant::object<
	Types
>::type_index() const
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
fcppt::variant::object<
	Types
>::construct(
	U const &_other
)
{
	new (
		this->raw_data()
	)
	typename fcppt::variant::detail::real_type<
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
		fcppt::variant::detail::index_of<
			Types,
			U
		>::value;
}

template<
	typename Types
>
void
fcppt::variant::object<
	Types
>::destroy()
{
	fcppt::variant::detail::apply_unary_internal(
		fcppt::variant::detail::destroy(),
		*this
	);
}

template<
	typename Types
>
void *
fcppt::variant::object<
	Types
>::raw_data()
{
	return
		&storage_;
}

template<
	typename Types
>
void const *
fcppt::variant::object<
	Types
>::raw_data() const
{
	return
		&storage_;
}

#endif
