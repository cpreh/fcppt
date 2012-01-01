//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_ARITHMETIC_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_ARITHMETIC_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/detail/strong_typedef_binary_operator.hpp>
#include <fcppt/detail/strong_typedef_unary_operator.hpp>


namespace fcppt
{

FCPPT_DETAIL_STRONG_TYPEDEF_BINARY_OPERATOR(+)
FCPPT_DETAIL_STRONG_TYPEDEF_BINARY_OPERATOR(-)
FCPPT_DETAIL_STRONG_TYPEDEF_BINARY_OPERATOR(*)
FCPPT_DETAIL_STRONG_TYPEDEF_BINARY_OPERATOR(/)
FCPPT_DETAIL_STRONG_TYPEDEF_BINARY_OPERATOR(%)

FCPPT_DETAIL_STRONG_TYPEDEF_UNARY_OPERATOR(+)
FCPPT_DETAIL_STRONG_TYPEDEF_UNARY_OPERATOR(-)

template<
	typename T,
	typename Tag
>
strong_typedef<
	T,
	Tag
> &
operator++(
	strong_typedef<
		T,
		Tag
	> &_value
)
{
	++_value.get();

	return _value;
}

template<
	typename T,
	typename Tag
>
strong_typedef<
	T,
	Tag
> &
operator--(
	strong_typedef<
		T,
		Tag
	> &_value
)
{
	--_value.get();

	return _value;
}

template<
	typename T,
	typename Tag
>
strong_typedef<
	T,
	Tag
>
operator++(
	strong_typedef<
		T,
		Tag
	> &_value,
	int
)
{
	strong_typedef<
		T,
		Tag
	> const temp(
		_value
	);

	++_value;

	return temp;
}

template<
	typename T,
	typename Tag
>
strong_typedef<
	T,
	Tag
>
operator--(
	strong_typedef<
		T,
		Tag
	> &_value,
	int
)
{
	strong_typedef<
		T,
		Tag
	> const temp(
		_value
	);

	--_value;

	return temp;
}

}

#endif
