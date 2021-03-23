//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_HASH_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_HASH_IMPL_HPP_INCLUDED

#include <fcppt/math/to_array.hpp>
#include <fcppt/math/to_array_type.hpp>
#include <fcppt/math/detail/hash_decl.hpp>
#include <fcppt/range/hash_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

template <typename Type>
inline std::size_t fcppt::math::detail::hash<Type>::operator()(Type const &_value) const
{
  return fcppt::range::hash<fcppt::math::to_array_type<Type>>{}(fcppt::math::to_array(_value));
}

#endif
