//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_DETAIL_BIT_STRINGS_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DETAIL_BIT_STRINGS_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::vector::detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

template <fcppt::math::size_type N, typename ForwardIterator, typename Vector>
std::enable_if_t<N == 0U, void> bit_strings(ForwardIterator &it, Vector _vector)
{
  fcppt::math::vector::at<N>(_vector) = fcppt::literal<fcppt::type_traits::value_type<Vector>>(0);

  *it++ = _vector;

  fcppt::math::vector::at<N>(_vector) = fcppt::literal<fcppt::type_traits::value_type<Vector>>(1);

  *it++ = _vector;
}

FCPPT_PP_POP_WARNING

template <fcppt::math::size_type N, typename ForwardIterator, typename Vector>
std::enable_if_t<N != 0U, void> bit_strings(ForwardIterator &it, Vector _vector)
{
  fcppt::math::vector::at<N>(_vector) = fcppt::literal<fcppt::type_traits::value_type<Vector>>(0);

  fcppt::math::vector::detail::bit_strings<N - 1U>(it, _vector);

  fcppt::math::vector::at<N>(_vector) = fcppt::literal<fcppt::type_traits::value_type<Vector>>(1);

  fcppt::math::vector::detail::bit_strings<N - 1U>(it, _vector);
}

}

#endif
