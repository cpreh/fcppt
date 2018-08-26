//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_COMPARISON_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_COMPARISON_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>


namespace fcppt
{

/**
\brief Operator less.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
bool
operator<(
	fcppt::strong_typedef<
		T,
		Tag
	> const &_left,
	fcppt::strong_typedef<
		T,
		Tag
	> const &_right
)
{
	return
		_left.get()
		<
		_right.get();
}

/**
\brief Operator less equal.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
bool
operator<=(
	fcppt::strong_typedef<
		T,
		Tag
	> const &_left,
	fcppt::strong_typedef<
		T,
		Tag
	> const &_right
)
{
	return
		_left.get()
		<=
		_right.get();
}

/**
\brief Operator greater.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
bool
operator>(
	fcppt::strong_typedef<
		T,
		Tag
	> const &_left,
	fcppt::strong_typedef<
		T,
		Tag
	> const &_right
)
{
	return
		_left.get()
		>
		_right.get();
}

/**
\brief Operator greater equal.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
bool
operator>=(
	fcppt::strong_typedef<
		T,
		Tag
	> const &_left,
	fcppt::strong_typedef<
		T,
		Tag
	> const &_right
)
{
	return
		_left.get()
		>=
		_right.get();
}

/**
\brief Operator equal.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
bool
operator==(
	fcppt::strong_typedef<
		T,
		Tag
	> const &_left,
	fcppt::strong_typedef<
		T,
		Tag
	> const &_right
)
{
	return
		_left.get()
		==
		_right.get();
}

/**
\brief Operator not equal.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
bool
operator!=(
	fcppt::strong_typedef<
		T,
		Tag
	> const &_left,
	fcppt::strong_typedef<
		T,
		Tag
	> const &_right
)
{
	return
		_left.get()
		!=
		_right.get();
}

}

#endif
