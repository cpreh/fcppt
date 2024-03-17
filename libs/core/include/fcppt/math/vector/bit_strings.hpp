//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_BIT_STRINGS_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_BIT_STRINGS_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/math/power_of_2.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/null.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/detail/bit_strings.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::vector
{
/**
\brief Generates vectors consisting of zeros and ones

\ingroup fcpptmathvector

\tparam T An integral type

Generates the bit strings of type <code>T</code> in dimension
<code>N</code>. Examples:

<pre>
T = int,
N = 2:

(0,0)
(1,0)
(0,1)
(1,1)

T = int,
N = 3:
(0,0,0)
(1,0,0)
(0,1,0)
(1,1,0)
(0,0,1)
(1,0,1)
(0,1,1)
(1,1,1)
</pre>

Example:

\snippet math/vector/bit_strings.cpp bit_strings
*/
template <typename T, fcppt::math::size_type N>
fcppt::array::object<
    fcppt::math::vector::static_<T, N>,
    fcppt::math::power_of_2<std::size_t>(
        // Workaround for VC++ a bug
        fcppt::math::size_type{N})> // NOLINT(readability-redundant-casting)
bit_strings()
{
  using vector_type = fcppt::math::vector::static_<T, N>;

  using result_type = fcppt::array::object<
      vector_type,
      fcppt::math::power_of_2<std::size_t>(
          // Workaround for a VC++ bug
          fcppt::math::size_type{N})>; // NOLINT(readability-redundant-casting)

  auto result(fcppt::array::init<result_type>(
      [](auto) { return fcppt::math::vector::null<vector_type>(); }));

  auto it{result.begin()};

  fcppt::math::vector::detail::bit_strings<
      N - fcppt::literal<fcppt::math::size_type>(1),
      typename result_type::iterator,
      vector_type>(it, fcppt::math::vector::null<vector_type>());

  return result;
}

}

#endif
