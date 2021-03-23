//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_STRONG_TYPEDEF_MAP_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_MAP_HPP_INCLUDED

#include <fcppt/is_strong_typedef.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_tag.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>

namespace fcppt
{
/**
\brief Maps over a strong typedef.

\ingroup fcpptstrongtypedef

Returns a strong typedef with the same tag type and value <code>_function(_input.get())</code>.

\tparam StrongTypedef Must be an #fcppt::strong_typedef.

\tparam Function Must be a function callable as <code>R (StrongTypedef::value_type)</code>,
where <code>R</code> is the result type.
*/
template <typename StrongTypedef, typename Function>
inline auto strong_typedef_map(StrongTypedef &&_input, Function const &_function)
    -> fcppt::strong_typedef<
        decltype(_function(fcppt::move_if_rvalue<StrongTypedef>(_input.get()))),
        fcppt::strong_typedef_tag<fcppt::type_traits::remove_cv_ref_t<StrongTypedef>>>
{
  using input_type = fcppt::type_traits::remove_cv_ref_t<StrongTypedef>;

  static_assert(
      fcppt::is_strong_typedef<input_type>::value, "StrongTypedef must be a strong typedef");

  return fcppt::strong_typedef<
      decltype(_function(fcppt::move_if_rvalue<StrongTypedef>(_input.get()))),
      fcppt::strong_typedef_tag<input_type>>(
      _function(fcppt::move_if_rvalue<StrongTypedef>(_input.get())));
}

}

#endif
