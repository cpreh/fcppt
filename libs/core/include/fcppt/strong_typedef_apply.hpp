//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_STRONG_TYPEDEF_APPLY_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_APPLY_HPP_INCLUDED

#include <fcppt/is_strong_typedef.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_tag.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/all_of.hpp>
#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Applies a function to multiple strong typedefs.

\ingroup fcpptstrongtypedef

Returns a strong typedef with the same tag type and value
<code>_function(_strong_typedef.get(), _strongs_typedefs.get()...)</code>.

\tparam StrongTypedef1 Must be an #fcppt::strong_typedef.

\tparam StrongTypedefs Must all be #fcppt::strong_typedef.

\tparam Function Must be a function callable as
<code>R (StrongTypedef1::value_type, StrongTypedefs::value_type...)</code>,
where <code>R</code> is the result type.
*/
template <typename StrongTypedef1, typename Function, typename... StrongTypedefs>
inline auto strong_typedef_apply(
    Function const &_function,
    StrongTypedef1 &&_strong_typedef1, // NOLINT(cppcoreguidelines-missing-std-forward)
    StrongTypedefs &&..._strong_typedefs) // NOLINT(cppcoreguidelines-missing-std-forward)
    -> fcppt::strong_typedef<
        decltype(_function(
            fcppt::move_if_rvalue<StrongTypedef1>(_strong_typedef1.get()),
            fcppt::move_if_rvalue<StrongTypedefs>(_strong_typedefs.get())...)),
        fcppt::strong_typedef_tag<std::remove_cvref_t<StrongTypedef1>>>
{
  using strong_typedef1 = std::remove_cvref_t<StrongTypedef1>;

  static_assert(
      fcppt::is_strong_typedef<strong_typedef1>::value, "StrongTypedef1 must be a strong typedef");

  using strong_typedefs = fcppt::mpl::list::object<std::remove_cvref_t<StrongTypedefs>...>;

  using input_tag = fcppt::strong_typedef_tag<strong_typedef1>;

  static_assert(
      fcppt::mpl::list::all_of<strong_typedefs, fcppt::mpl::lambda<fcppt::is_strong_typedef>>::value,
      "StrongTypedefs must all be strong typedefs");

  static_assert(
      fcppt::mpl::list::all_of<
          strong_typedefs,
          fcppt::mpl::bind<
              fcppt::mpl::lambda<std::is_same>,
              fcppt::mpl::constant<input_tag>,
              fcppt::mpl::lambda<fcppt::strong_typedef_tag>>>::value,
      "All strong typedefs must have the same tag type");

  return fcppt::strong_typedef<
      decltype(_function(
          fcppt::move_if_rvalue<StrongTypedef1>(_strong_typedef1.get()),
          fcppt::move_if_rvalue<StrongTypedefs>(_strong_typedefs.get())...)),
      input_tag>(_function(
      fcppt::move_if_rvalue<StrongTypedef1>(_strong_typedef1.get()),
      fcppt::move_if_rvalue<StrongTypedefs>(_strong_typedefs.get())...));
}

}

#endif
