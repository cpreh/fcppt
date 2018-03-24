//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/detail/call_destructor.hpp>
#include <fcppt/detail/placement_new.hpp>
#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_decl.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/variant/detail/assert_type.hpp>
#include <fcppt/variant/detail/disable_object.hpp>
#include <fcppt/variant/detail/index_of.hpp>
#include <fcppt/variant/detail/nothrow_move_assignable.hpp>
#include <fcppt/variant/detail/nothrow_move_constructible.hpp>
#include <fcppt/config/external_begin.hpp>
#include <new>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


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
	fcppt::variant::detail::disable_object<
		U,
		object
	> *
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
		[
			this
		](
			auto const &_other_inner
		)
		{
			fcppt::detail::placement_new(
				this->raw_data(),
				_other_inner
			);
		},
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
noexcept(
	fcppt::variant::detail::nothrow_move_constructible<
		Types
	>::value
)
:
	storage_(),
	index_(
		_other.index_
	)
{
	fcppt::variant::apply_unary(
		[
			this
		](
			auto &&_value
		)
		{
			fcppt::detail::placement_new(
				this->raw_data(),
				std::move(
					_value
				)
			);
		},
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
		this->template get_unsafe<
			U
		>() =
			_other;
	else
	{
		this->destroy();

		this->construct(
			_other
		);
	}

	return
		*this;
}

template<
	typename Types
>
template<
	typename U
>
fcppt::variant::detail::disable_object<
	U,
	fcppt::variant::object<
		Types
	>
> &
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
		this-> template get_unsafe<
			typename
			std::decay<
				U
			>::type
		>() =
			std::move(
				_other
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

	return
		*this;
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
			[
				this
			](
				auto const &_other_inner
			)
			{
				this-> template get_unsafe<
					typename
					std::decay<
						decltype(
							_other_inner
						)
					>::type
				>() =
					_other_inner;
			},
			_other
		);
	else
		fcppt::variant::apply_unary(
			[
				this
			](
				auto const &_value
			)
			{
				*this =
					_value;
			},
			_other
		);

	return
		*this;
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
noexcept(
	fcppt::variant::detail::nothrow_move_assignable<
		Types
	>::value
)
{
	if(
		index_
		==
		_other.type_index()
	)
		fcppt::variant::apply_unary(
			[
				this
			](
				auto &&_other_inner
			)
			{
				this->template get_unsafe<
					typename
					std::decay<
						decltype(
							_other_inner
						)
					>::type
				>() =
					std::move(
						_other_inner
					);
			},
			std::move(
				_other
			)
		);
	else
		this->swap_unequal(
			_other
		);

	return
		*this;
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
U &
fcppt::variant::object<
	Types
>::get_unsafe()
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
>::get_unsafe() const
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
	std::remove_reference_t<
		U
	>(
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
		[](
			auto &_value
		)
		{
			fcppt::detail::call_destructor(
				_value
			);
		},
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
		[
			&_other,
			this
		](
			auto &_left,
			auto &_right
		)
		{
			auto temp(
				std::move(
					_left
				)
			);

			*this =
				std::move(
					_right
				);

			_other =
				std::move(
					temp
				);
		},
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
