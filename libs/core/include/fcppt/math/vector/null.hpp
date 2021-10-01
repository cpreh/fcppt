//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_NULL_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_NULL_HPP_INCLUDED

#include <fcppt/math/detail/null_storage.hpp>
#include <fcppt/math/vector/is_vector.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/type_traits/value_type.hpp>

namespace fcppt::math::vector
{
/**
\brief Returns the null vector

\ingroup fcpptmathvector
*/
template <typename Vector>
fcppt::math::vector::static_<fcppt::type_traits::value_type<Vector>, Vector::static_size::value>
null()
{
  static_assert(fcppt::math::vector::is_vector<Vector>::value, "Vector must be a vector");

  using result_type = fcppt::math::vector::
      static_<fcppt::type_traits::value_type<Vector>, Vector::static_size::value>;

  return result_type(fcppt::math::detail::null_storage<typename result_type::storage_type>());
}

}

#endif
