#ifndef FCPPT_MATH_DETAIL_GENERATE_BINARY_VECTORS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_GENERATE_BINARY_VECTORS_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <boost/utility/enable_if.hpp>
#include <cstddef>

namespace fcppt
{
namespace math
{
namespace detail
{
template<fcppt::math::size_type N,typename ResultVector>
typename
boost::enable_if_c
<
	N == static_cast<fcppt::math::size_type>(0),
	void
>::type
generate_binary_vectors(
	ResultVector &vs,
	typename ResultVector::value_type v)
{
	v[N] = 
		static_cast<typename ResultVector::value_type::value_type>(
			0);
	vs.push_back(
		v);
	v[N] = 
		static_cast<typename ResultVector::value_type::value_type>(
			1);
	vs.push_back(
		v);
}

template<fcppt::math::size_type N,typename ResultVector>
typename
boost::enable_if_c
<
	N != static_cast<fcppt::math::size_type>(0),
	void
>::type
generate_binary_vectors(
	ResultVector &vs,
	typename ResultVector::value_type v)
{
	v[N] = 0;
	fcppt::math::detail::generate_binary_vectors<static_cast<fcppt::math::size_type>(N-1)>(
		vs,
		v);
	v[N] = 1;
	fcppt::math::detail::generate_binary_vectors<static_cast<fcppt::math::size_type>(N-1)>(
		vs,
		v);
}
}
}
}

#endif
