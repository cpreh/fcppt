//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_MAKE_HPP_INCLUDED
#define FCPPT_ARRAY_MAKE_HPP_INCLUDED

#include <fcppt/array/object_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
/**
\brief Make an array out of a parameter pack.

\ingroup fcpptarray

Let \a _args be <code>(a_1,...,a_n)</code>. All elements of \a _args must be of
the same type <code>T</code>. The result is
<code>fcppt::array::object<T,n>{a_1,...,a_n}</code>.

\tparam Args A parameter pack <code>t_1,...,t_n</code> such that
<code>remove_cv_ref<t_1> = ... = remove_cv_ref<t_n></code>.
*/
template <
    typename Arg1,
    typename... Args,
    typename = std::enable_if_t<std::conjunction_v<std::is_same<
        fcppt::type_traits::remove_cv_ref_t<Arg1>,
        fcppt::type_traits::remove_cv_ref_t<Args>>...>>>
inline fcppt::array::object<fcppt::type_traits::remove_cv_ref_t<Arg1>, sizeof...(Args) + 1U>
make(Arg1 &&_arg1, Args &&..._args)
{
  using result_type =
      fcppt::array::object<fcppt::type_traits::remove_cv_ref_t<Arg1>, sizeof...(Args) + 1U>;

  return result_type{std::forward<Arg1>(_arg1), std::forward<Args>(_args)...};
}
}

#endif
