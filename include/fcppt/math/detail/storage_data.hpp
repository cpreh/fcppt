//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STORAGE_DATA_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STORAGE_DATA_HPP_INCLUDED

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
typename T::value_type *
storage_data(
	T &t
)
{
	return t.data();
}

template<
	typename T
>
typename T::value_type const *
storage_data(
	T const &t
)
{
	return t.data();
}

}
}
}

#endif
