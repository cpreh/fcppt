//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_LENGTH_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_LENGTH_HPP_INCLUDED

#include <fcppt/cast/int_to_float.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/length_square.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::vector
{
/**
\brief Calculates the length of a vector
\ingroup fcpptmathvector

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
fcppt::math::vector::static_<float,3>
vector3f;

typedef
fcppt::math::vector::static_<int,3>
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
template <typename T, fcppt::math::size_type N, typename S>
inline T length(fcppt::math::vector::object<T, N, S> const &_vec)
  requires(std::is_floating_point_v<T>)
{
  return std::sqrt(fcppt::math::vector::length_square(_vec));
}

/**
\brief Calculates the length of a vector
\ingroup fcpptmathvector

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
fcppt::math::vector::static_<float,3>
vector3f;

typedef
fcppt::math::vector::static_<int,3>
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
template <typename Dest, typename T, fcppt::math::size_type N, typename S>
inline Dest length(fcppt::math::vector::object<T, N, S> const &_vec)
  requires(!std::is_floating_point_v<T>)
{
  return std::sqrt(fcppt::cast::int_to_float<Dest>(fcppt::math::vector::length_square(_vec)));
}
}

#endif
