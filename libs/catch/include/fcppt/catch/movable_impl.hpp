//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CATCH_MOVABLE_IMPL_HPP_INCLUDED
#define FCPPT_CATCH_MOVABLE_IMPL_HPP_INCLUDED

#include <fcppt/catch/movable_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Type
>
fcppt::catch_::movable<
	Type
>::movable(
	Type const &_value
)
:
	value_{
		_value
	}
{
}

template<
	typename Type
>
fcppt::catch_::movable<
	Type
>::movable(
	Type &&_value
)

:
	value_{
		std::move(
			_value
		)
	}
{
}

template<
	typename Type
>
fcppt::catch_::movable<
	Type
>::movable(
	movable &&_other
)
noexcept(
	std::is_nothrow_move_constructible<
		Type
	>::value
)
:
	value_{
		std::move(
			_other.value()
		)
	}
{
}

template<
	typename Type
>
fcppt::catch_::movable<
	Type
> &
fcppt::catch_::movable<
	Type
>::operator=(
	movable &&_other
)
noexcept(
	std::is_nothrow_move_assignable<
		Type
	>::value
)
{
	value_ =
		std::move(
			_other.value()
		);

	return
		*this;
}

template<
	typename Type
>
fcppt::catch_::movable<
	Type
>::~movable()
{
}

template<
	typename Type
>
Type &
fcppt::catch_::movable<
	Type
>::value()
{
	return
		value_;
}

template<
	typename Type
>
Type const &
fcppt::catch_::movable<
	Type
>::value() const
{
	return
		value_;
}

#endif
