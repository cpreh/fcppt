//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_LENGTH_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_LENGTH_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/length_square.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Calculates the length of a vector
\ingroup fcpptmathvector
\tparam T The vector's <code>value_type</code>. Must be a floating point type.
\tparam N The vector's dimension type
\tparam S The vector's storage type

This is the Euclidean distance (or 2 norm) of the vector. There are two
variants of this function. One works only for floating point vectors (so you
don't have to specify the return type). The other one works for arbitrary
vectors and uses a cast internally.

\note
If you want the length <em>squared</em>, use fcppt::math::vector::length_square

\see
fcppt::math::vector::length_square

Example:

\code
typedef
fcppt::math::vector::static_<float,3>::type
vector3f;

typedef
fcppt::math::vector::static_<int,3>::type
vector3i;

vector3f vf(1.0f,2.0f,3.0f);
vector3f vi(1,2,3);

// No need to specify the return type here, it'll be float.
float vf_length =
	fcppt::math::vector::length(
		vf);

// It's not so clear here. So we specify "float" explicitly
float vi_length =
	fcppt::math::vector::length<float>(
		vi);

// Hopefully, this prints "true"
std::cout << (std::abs(vf_length - vi_length) < 0.001f);
\endcode
*/
/**
\brief Calculates the length of a vector
\ingroup fcpptmathvector
\tparam T The vector's <code>value_type</code>. Must be a floating point type.
\tparam N The vector's dimension type
\tparam S The vector's storage type


*/
template<
	typename T,
	typename N,
	typename S
>
typename boost::enable_if<
	boost::is_floating_point<T>,
	typename basic<T, N, S>::value_type
>::type
length(
	basic<T, N, S> const &v
)
{
	return
		std::sqrt(
			length_square(
				v
			)
		);
}

/**
\brief Calculates the length of a vector
\ingroup fcpptmathvector
\tparam T The vector's <code>value_type</code>. Cannot be a floating point type.
\tparam N The vector's dimension type
\tparam S The vector's storage type

This is the Euclidean distance (or 2 norm) of the vector. There are two
variants of this function. One works only for floating point vectors (so you
don't have to specify the return type). The other one works for arbitrary
vectors and uses a cast internally.

\note
If you want the length <em>squared</em>, use fcppt::math::vector::length_square

\see
fcppt::math::vector::length_square

Example:

\code
typedef
fcppt::math::vector::static_<float,3>::type
vector3f;

typedef
fcppt::math::vector::static_<int,3>::type
vector3i;

vector3f vf(1.0f,2.0f,3.0f);
vector3f vi(1,2,3);

// No need to specify the return type here, it'll be float.
float vf_length =
	fcppt::math::vector::length(
		vf);

// It's not so clear here. So we specify "float" explicitly
float vi_length =
	fcppt::math::vector::length<float>(
		vi);

// Hopefully, this prints "true"
std::cout << (std::abs(vf_length - vi_length) < 0.001f);
\endcode
*/
template<
	typename Dest,
	typename T,
	typename N,
	typename S
>
typename boost::disable_if<
	boost::is_floating_point<T>,
	Dest
>::type
length(
	basic<T, N, S> const &v
)
{
	return
		std::sqrt(
			static_cast<Dest>(
				length_square(
					v
				)
			)
		);
}

}
}
}

#endif
