//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_LINEAR_ACCESS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_LINEAR_ACCESS_HPP_INCLUDED


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Container
>
typename
Container::value_type &
linear_access(
	Container &_container,
	typename Container::size_type const _index
)
{
	return
		*(_container.data() + _index);
}

template<
	typename Container
>
typename
Container::value_type const &
linear_access(
	Container const &_container,
	typename Container::size_type const _index
)
{
	return
		*(_container.data() + _index);
}

}
}
}

#endif
