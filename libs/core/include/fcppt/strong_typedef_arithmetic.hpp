//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_ARITHMETIC_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_ARITHMETIC_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>


namespace fcppt
{

/**
\brief Add two strong typedefs.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
fcppt::strong_typedef<
	T,
	Tag
>
operator+(
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
		fcppt::strong_typedef<
			T,
			Tag
		>{
			_left.get()
			+
			_right.get()
		};
}

/**
\brief Subtract two strong typedefs.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
fcppt::strong_typedef<
	T,
	Tag
>
operator-(
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
		fcppt::strong_typedef<
			T,
			Tag
		>{
			_left.get()
			-
			_right.get()
		};
}

/**
\brief Multiply two strong typedefs.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
fcppt::strong_typedef<
	T,
	Tag
>
operator*(
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
		fcppt::strong_typedef<
			T,
			Tag
		>{
			_left.get()
			*
			_right.get()
		};
}

/**
\brief Unary minus.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
fcppt::strong_typedef<
	T,
	Tag
>
operator -(
	fcppt::strong_typedef<
		T,
		Tag
	> const &_value
)
{
	return
		fcppt::strong_typedef<
			T,
			Tag
		>{
			-_value.get()
		};
}

/**
\brief Preincrement operator.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
fcppt::strong_typedef<
	T,
	Tag
> &
operator ++(
	fcppt::strong_typedef<
		T,
		Tag
	> &_value
)
{
	++_value.get();

	return
		_value;
}

/**
\brief Predecrement operator.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
fcppt::strong_typedef<
	T,
	Tag
> &
operator --(
	fcppt::strong_typedef<
		T,
		Tag
	> &_value
)
{
	--_value.get();

	return
		_value;
}

/**
\brief Postincrement operator.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
fcppt::strong_typedef<
	T,
	Tag
>
operator ++(
	fcppt::strong_typedef<
		T,
		Tag
	> &_value,
	int
)
{
	fcppt::strong_typedef<
		T,
		Tag
	> const temp{
		_value
	};

	++_value;

	return
		temp;
}

/**
\brief Postdecrement operator.

\ingroup fcpptstrongtypedef
*/
template<
	typename T,
	typename Tag
>
inline
fcppt::strong_typedef<
	T,
	Tag
>
operator --(
	fcppt::strong_typedef<
		T,
		Tag
	> &_value,
	int
)
{
	fcppt::strong_typedef<
		T,
		Tag
	> const temp{
		_value
	};

	--_value;

	return
		temp;
}

}

#endif
