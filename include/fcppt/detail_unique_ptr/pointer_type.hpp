// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010-2012 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_DETAIL_UNIQUE_PTR_POINTER_TYPE_HPP_INCLUDED
#define FCPPT_DETAIL_UNIQUE_PTR_POINTER_TYPE_HPP_INCLUDED

#include <fcppt/null_ptr.hpp>
#include <fcppt/detail_unique_ptr/one_two.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail_unique_ptr
{
namespace pointer_type_imp
{

template<
	typename U
>
two
test(...);

template<
	typename U
>
one
test(
	typename U::pointer * = fcppt::null_ptr()
);

}  // pointer_type_imp

template<
	typename T
>
struct has_pointer_type
{
	static bool const value =
		sizeof(
			pointer_type_imp::test<T>(
				fcppt::null_ptr()
			)
		) == 1;
};

namespace pointer_type_imp
{

template<
	typename T, typename D,
	bool = has_pointer_type<D>::value
>
struct pointer_type
{
	typedef typename D::pointer type;
};

template<
	typename T,
	typename D
>
struct pointer_type<T, D, false>
{
	typedef T* type;
};

}  // pointer_type_imp

template<
	typename T,
	typename D
>
struct pointer_type
{
	typedef typename pointer_type_imp::pointer_type<
		T,
		typename boost::remove_reference<D>::type
	>::type type;
};

}  // detail_unique_ptr
}

#endif
