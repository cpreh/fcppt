//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_FOREACH_ENUMERATOR_VAR_IMPL_HPP_INCLUDED
#define FCPPT_DETAIL_FOREACH_ENUMERATOR_VAR_IMPL_HPP_INCLUDED

#include <fcppt/enum_size.hpp>
#include <fcppt/detail/foreach_enumerator_var_decl.hpp>


template<
	typename Enum
>
fcppt::detail::foreach_enumerator_var<
	Enum
>::foreach_enumerator_var(
	Enum const _start
)
:
	foreach_enumerator_var(
		_start,
		fcppt::enum_size<
			Enum
		>::value
	)
{
}

template<
	typename Enum
>
fcppt::detail::foreach_enumerator_var<
	Enum
>::foreach_enumerator_var(
	Enum const _start,
	Enum const _end
)
:
	foreach_enumerator_var(
		_start,
		static_cast<
			size_type
		>(
			_end
		)
		+
		1u
	)
{
}

template<
	typename Enum
>
fcppt::detail::foreach_enumerator_var<
	Enum
>::~foreach_enumerator_var()
{
}

template<
	typename Enum
>
bool
fcppt::detail::foreach_enumerator_var<
	Enum
>::running() const
{
	return
		index_ != end_;
}

template<
	typename Enum
>
void
fcppt::detail::foreach_enumerator_var<
	Enum
>::increment()
{
	++index_;
}

template<
	typename Enum
>
fcppt::detail::foreach_enumerator_var<
	Enum
>::operator
Enum() const
{
	return
		static_cast<
			Enum
		>(
			index_
		);
}

template<
	typename Enum
>
fcppt::detail::foreach_enumerator_var<
	Enum
>::operator
typename
fcppt::detail::foreach_enumerator_var<
	Enum
>::size_type() const
{
	return
		index_;
}

template<
	typename Enum
>
fcppt::detail::foreach_enumerator_var<
	Enum
>::foreach_enumerator_var(
	Enum const _start,
	size_type const _end
)
:
	index_(
		static_cast<
			size_type
		>(
			_start
		)
	),
	end_(
		_end
	)
{
}

#endif
