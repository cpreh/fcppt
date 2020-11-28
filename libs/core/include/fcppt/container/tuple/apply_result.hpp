//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_TUPLE_APPLY_RESULT_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_APPLY_RESULT_HPP_INCLUDED

#include <fcppt/container/tuple/detail/apply_result_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace tuple
{
/**
\brief Result of #fcppt::container::tuple::apply.

\ingroup fcpptcontainertuple
*/
template <typename Function, typename... Tuples>
using apply_result = typename fcppt::container::tuple::detail::apply_result_impl<
    Function,
    std::make_index_sequence<std::tuple_size<::metal::front<::metal::list<Tuples...>>>::value>,
    Tuples...>::type;

}
}
}

#endif
