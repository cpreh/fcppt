//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_DETAIL_BIT_STRINGS_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DETAIL_BIT_STRINGS_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{
namespace detail
{

template<
	fcppt::math::size_type N,
	typename ForwardIterator,
	typename Vector
>
typename
std::enable_if<
	N == 0u,
	void
>::type
bit_strings(
	ForwardIterator &it,
	Vector v)
{
	v[N] =
		fcppt::literal<typename Vector::value_type>(
			0);
	*it++ =
		v;
	v[N] =
		fcppt::literal<typename Vector::value_type>(
			1);
	*it++ =
		v;
}

template<
	fcppt::math::size_type N,
	typename ForwardIterator,
	typename Vector
>
typename
std::enable_if<
	N != 0u,
	void
>::type
bit_strings(
	ForwardIterator &it,
	Vector v
)
{
	v[N] =
		fcppt::literal<typename Vector::value_type>(
			0);

	fcppt::math::vector::detail::bit_strings<
		N - fcppt::literal<fcppt::math::size_type>(1)
	>(
		it,
		v
	);

	v[N] =
		fcppt::literal<typename Vector::value_type>(
			1);

	fcppt::math::vector::detail::bit_strings<
		N - fcppt::literal<fcppt::math::size_type>(1)
	>(
		it,
		v
	);
}

}
}
}
}

#endif
