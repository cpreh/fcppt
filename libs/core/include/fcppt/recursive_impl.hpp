//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECURSIVE_IMPL_HPP_INCLUDED
#define FCPPT_RECURSIVE_IMPL_HPP_INCLUDED

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/recursive_decl.hpp>
#include <fcppt/unique_ptr_impl.hpp>


template<
	typename Type
>
fcppt::recursive<
	Type
>::recursive(
	Type const &_value
)
:
	impl_{
		fcppt::make_unique_ptr<
			Type
		>(
			_value
		)
	}
{
}

template<
	typename Type
>
fcppt::recursive<
	Type
>::recursive(
	Type &&_value
)
:
	impl_{
		fcppt::make_unique_ptr<
			Type
		>(
			std::move(
				_value
			)
		)
	}
{
}

template<
	typename Type
>
fcppt::recursive<
	Type
>::recursive(
	recursive const &_other
)
:
	impl_{
		fcppt::make_unique_ptr<
			Type
		>(
			_other.get()
		)
	}
{
}

template<
	typename Type
>
fcppt::recursive<
	Type
>::recursive(
	recursive &&
) noexcept
= default;

template<
	typename Type
>
fcppt::recursive<
	Type
> &
fcppt::recursive<
	Type
>::operator=( // NOLINT(cert-oop54-cpp)
	recursive const &_other
)
{
	if(
		this
		==
		&_other
	)
	{
		return
			*this;
	}

	impl_ =
		fcppt::make_unique_ptr<
			Type
		>(
			_other.get()
		);

	return
		*this;
}

template<
	typename Type
>
fcppt::recursive<
	Type
> &
fcppt::recursive<
	Type
>::operator=(
	recursive &&
) noexcept
= default;

template<
	typename Type
>
fcppt::recursive<
	Type
>::~recursive()
= default;

template<
	typename Type
>
Type &
fcppt::recursive<
	Type
>::get()
{
	return
		*impl_;
}

template<
	typename Type
>
Type const &
fcppt::recursive<
	Type
>::get() const
{
	return
		*impl_;
}

#endif
