//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_PUSH_BACK_HPP_INCLUDED
#define FCPPT_TUPLE_PUSH_BACK_HPP_INCLUDED

#include <fcppt/tuple/is_object.hpp>
#include <fcppt/tuple/push_back_result.hpp>
#include <fcppt/tuple/size.hpp>
#include <fcppt/tuple/detail/push_back.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief Pushes an element to the back of a <code>fcppt::tuple::object</code>.

\ingroup fcppttuple

Let \a _tuple be <code>(v_1,...,v_n)</code>.
The result of the function is <code>(v_1,...,v_n,_new_element)</code>.

\tparam Tuple Must be a <code>fcppt::tuple::object</code>.
*/
template <typename Tuple, typename NewElement>
fcppt::tuple::push_back_result<
    fcppt::type_traits::remove_cv_ref_t<Tuple>,
    fcppt::type_traits::remove_cv_ref_t<NewElement>>
push_back(Tuple &&_tuple, NewElement &&_new_element)
{
  using source_type = fcppt::type_traits::remove_cv_ref_t<Tuple>;

  static_assert(
      fcppt::tuple::is_object<source_type>::value,
      "Tuple must be an fcppt::tuple::object");

  return fcppt::tuple::detail::push_back<fcppt::tuple::push_back_result<
      source_type,
      fcppt::type_traits::remove_cv_ref_t<NewElement>>>(
      std::make_index_sequence<fcppt::tuple::size<source_type>::value>{},
      std::forward<Tuple>(_tuple),
      std::forward<NewElement>(_new_element));
}

}

#endif
