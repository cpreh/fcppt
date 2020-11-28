//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_TUPLE_PUSH_BACK_RESULT_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_PUSH_BACK_RESULT_HPP_INCLUDED

#include <fcppt/container/tuple/detail/push_back_result.hpp>

namespace fcppt
{
namespace container
{
namespace tuple
{
/**
\brief The result type of #fcppt::container::tuple::push_back.

\ingroup fcpptcontainertuple
*/
template <typename Tuple, typename NewElement>
using push_back_result =
    typename fcppt::container::tuple::detail::push_back_result<Tuple, NewElement>::type;

}
}
}

#endif
