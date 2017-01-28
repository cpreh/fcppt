//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_IMPL_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/strong_typedef_decl.hpp>
#include <fcppt/detail/strong_typedef/cast.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	typename Tag
>
template<
	typename U
>
fcppt::strong_typedef<
	T,
	Tag
>::strong_typedef(
	U const &_other
)
:
	value_(
		fcppt::detail::strong_typedef_cast<
			T
		>(
			_other
		)
	)
{
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	typename Tag
>
fcppt::strong_typedef<
	T,
	Tag
>::strong_typedef(
	fcppt::no_init const &
)
{
}

FCPPT_PP_POP_WARNING

template<
	typename T,
	typename Tag
>
fcppt::strong_typedef<
	T,
	Tag
>::strong_typedef(
	T &&_value
)
:
	value_(
		std::move(
			_value
		)
	)
{
}

template<
	typename T,
	typename Tag
>
T const &
fcppt::strong_typedef<
	T,
	Tag
>::get() const
{
	return
		value_;
}

template<
	typename T,
	typename Tag
>
void
fcppt::strong_typedef<
	T,
	Tag
>::swap(
	fcppt::strong_typedef<
		T,
		Tag
	> &_other
)
{
	using std::swap;

	swap(
		value_,
		_other.value_
	);
}

template<
	typename T,
	typename Tag
>
void
fcppt::swap(
	fcppt::strong_typedef<
		T,
		Tag
	> &_a,
	fcppt::strong_typedef<
		T,
		Tag
	> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
