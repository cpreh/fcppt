// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_UNIQUE_PTR_DETAIL_IS_CONVERTIBLE_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_DETAIL_IS_CONVERTIBLE_HPP_INCLUDED

#include <fcppt/detail_unique_ptr/one_two.hpp>

namespace fcppt
{
namespace detail_unique_ptr
{

// An is_convertible<From, To> that considers From an rvalue (consistent with C++0X).
//   This is a simplified version neglecting the types function, array, void and abstract types
//   I had to make a special case out of is_convertible<T,T> to make move-only
//   types happy.

namespace is_conv_imp
{

template<
	typename T
>
one
test1(
	T const &
);

template<
	typename T
>
two
test1(...);

template<
	typename T
>
one
test2(
	T
);

template<
	typename T
>
two
test2(...);

template<
	typename T
>
T
source();

}

template<
	typename T1,
	typename T2
>
struct is_convertible
{
	static bool const value =
		sizeof(
			is_conv_imp::test1<T2>(
				is_conv_imp::source<T1>()
			)
		) == 1;
};

template<
	typename T
>
struct is_convertible<T, T>
{
	static bool const value =
		sizeof(
			is_conv_imp::test2<T>(
				is_conv_imp::source<T>()
			)
		) == 1;
};

}
}

#endif
