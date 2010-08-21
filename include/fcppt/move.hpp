#ifndef FCPPT_MOVE_HPP_INCLUDED
#define FCPPT_MOVE_HPP_INCLUDED

#include <fcppt/detail_unique_ptr/is_convertible.hpp>
#include <fcppt/detail_unique_ptr/rv.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{

template<
	typename T
>
inline
typename boost::enable_if_c
<
	!detail_unique_ptr::is_convertible<
		T,
		detail_unique_ptr::rv<T>
	>::value,
	T &
>::type
move(
	T &t
)
{
	return t;
}

template<
	class T
>
inline
typename boost::enable_if_c
<
	!detail_unique_ptr::is_convertible<
		T,
		detail_unique_ptr::rv<T>
	>::value,
	T const &
>::type
move(
	T const &t
)
{
	return t;
}

template<
	typename T
>
inline
typename boost::enable_if_c
<
	detail_unique_ptr::is_convertible<
		T,
		detail_unique_ptr::rv<T>
	>::value,
	T
>::type
move(T& t)
{
	return T(detail_unique_ptr::rv<T>(t));
}

}

#endif
