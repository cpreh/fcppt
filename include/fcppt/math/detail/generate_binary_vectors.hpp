//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_GENERATE_BINARY_VECTORS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_GENERATE_BINARY_VECTORS_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{
template<fcppt::math::size_type N,typename ForwardIterator,typename Vector>
typename
boost::enable_if_c
<
	N == static_cast<fcppt::math::size_type>(0),
	void
>::type
generate_binary_vectors(
	ForwardIterator &it,
	Vector v)
{
	v[static_cast<std::size_t>(N)] =
		static_cast<typename Vector::value_type>(
			0);
	*it++ =
		v;
	v[static_cast<std::size_t>(N)] =
		static_cast<typename Vector::value_type>(
			1);
	*it++ =
		v;
}

template<fcppt::math::size_type N,typename ForwardIterator,typename Vector>
typename
boost::enable_if_c
<
	N != static_cast<fcppt::math::size_type>(0),
	void
>::type
generate_binary_vectors(
	ForwardIterator &it,
	Vector v)
{
	v[static_cast<std::size_t>(N)] =
		static_cast<typename Vector::value_type>(
			0);
	fcppt::math::detail::generate_binary_vectors<static_cast<fcppt::math::size_type>(N-1),ForwardIterator,Vector>(
		it,
		v);
	v[static_cast<std::size_t>(N)] =
		static_cast<typename Vector::value_type>(
			1);
	fcppt::math::detail::generate_binary_vectors<static_cast<fcppt::math::size_type>(N-1),ForwardIterator,Vector>(
		it,
		v);
}
}
}
}

#endif
