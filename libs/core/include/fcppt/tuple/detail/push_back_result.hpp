//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_DETAIL_PUSH_BACK_RESULT_HPP_INCLUDED
#define FCPPT_TUPLE_DETAIL_PUSH_BACK_RESULT_HPP_INCLUDED

#include <fcppt/tuple/object_fwd.hpp>

namespace fcppt::tuple::detail
{
template <typename Tuple, typename NewElement>
struct push_back_result;

template <typename NewElement, typename... Types>
struct push_back_result<fcppt::tuple::object<Types...>, NewElement>
{
  using type = fcppt::tuple::object<Types..., NewElement>;
};

}

#endif
