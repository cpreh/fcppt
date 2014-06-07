//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/is_object.hpp>
#include <fcppt/variant/object_decl.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/variant/detail/assert_type.hpp>
#include <fcppt/variant/detail/assign_object.hpp>
#include <fcppt/variant/detail/assign_value.hpp>
#include <fcppt/variant/detail/construct.hpp>
#include <fcppt/variant/detail/copy.hpp>
#include <fcppt/variant/detail/destroy.hpp>
#include <fcppt/variant/detail/disable_object.hpp>
#include <fcppt/variant/detail/get_impl.hpp>
#include <fcppt/variant/detail/index_of.hpp>
#include <fcppt/variant/detail/move_assign_object.hpp>
#include <fcppt/variant/detail/move_assign_value.hpp>
#include <fcppt/variant/detail/move_construct.hpp>
#include <fcppt/variant/detail/swap_unequal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <new>
#include <type_traits>
#include <utility>
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

template<
	typename Types
>
template<
	typename U
>
fcppt::variant::object<
	Types
>::object(
	U &&_other,
	typename fcppt::variant::detail::disable_object<
		U
	>::type *
)
:
	storage_()
	// Don't initialize index_
{
	this->move_from(
		std::move(
			_other
		)
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
	fcppt::variant::apply_unary(
		fcppt::variant::detail::copy(
			this->raw_data()
		),
		_other
	);
}

template<
	typename Types
>
fcppt::variant::object<
	Types
>::object(
	object &&_other
)
:
	storage_(),
	index_(
		_other.index_
	)
{
	fcppt::variant::apply_unary(
		fcppt::variant::detail::move_construct(
			this->raw_data()
		),
		std::move(
			_other
		)
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
		fcppt::variant::apply_unary(
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
template<
	typename U
>
typename fcppt::variant::detail::disable_object<
	U,
	fcppt::variant::object<
		Types
	> &
>::type
fcppt::variant::object<
	Types
>::operator=(
	U &&_other
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
		fcppt::variant::apply_unary(
			fcppt::variant::detail::move_assign_value<
				U
			>(
				std::move(
					_other
				)
			),
			*this
		);
	else
	{
		this->destroy();

		this->move_from(
			std::move(
				_other
			)
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
		fcppt::variant::apply_unary(
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
		fcppt::variant::apply_unary(
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
> &
fcppt::variant::object<
	Types
>::operator=(
	object &&_other
)
{
	if(
		index_
		==
		_other.type_index()
	)
		fcppt::variant::apply_unary(
			fcppt::variant::detail::move_assign_object<
				fcppt::variant::object<
					Types
				>
			>(
				*this
			),
			std::move(
				_other
			)
		);
	else
		this->swap_unequal(
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
>::get_unchecked()
{
	FCPPT_VARIANT_DETAIL_ASSERT_TYPE(
		Types,
		U,
		elements
	);

	return
		*fcppt::cast::from_void_ptr<
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
>::get_unchecked() const
{
	FCPPT_VARIANT_DETAIL_ASSERT_TYPE(
		Types,
		U,
		elements
	);

	return
		*fcppt::cast::from_void_ptr<
			U const *
		>(
			this->raw_data()
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
	return
		index_;
}

template<
	typename Types
>
bool
fcppt::variant::object<
	Types
>::is_invalid() const
{
	return
		this->type_index()
		==
		elements;
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
	FCPPT_VARIANT_DETAIL_ASSERT_TYPE(
		Types,
		U,
		elements
	);

	new (
		this->raw_data()
	)
	U(
		_other
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
template<
	typename U
>
void
fcppt::variant::object<
	Types
>::move_from(
	U &&_other
)
{
	FCPPT_VARIANT_DETAIL_ASSERT_TYPE(
		Types,
		U,
		elements
	);

	new (
		this->raw_data()
	)
	typename std::remove_reference<
		U
	>::type(
		std::move(
			_other
		)
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
	if(
		this->is_invalid()
	)
		return;

	fcppt::variant::apply_unary(
		fcppt::variant::detail::destroy(),
		*this
	);

	index_ =
		elements;
}

template<
	typename Types
>
void
fcppt::variant::object<
	Types
>::swap_unequal(
	object &_other
)
{
	fcppt::variant::apply_binary(
		fcppt::variant::detail::swap_unequal<
			fcppt::variant::object<
				Types
			>
		>(
			*this,
			_other
		),
		*this,
		_other
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
