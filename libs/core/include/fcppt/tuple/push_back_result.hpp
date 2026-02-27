//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_PUSH_BACK_RESULT_HPP_INCLUDED
#define FCPPT_TUPLE_PUSH_BACK_RESULT_HPP_INCLUDED

#include <fcppt/tuple/detail/push_back_result.hpp>

namespace fcppt::tuple
{
/**
\brief The result type of #fcppt::tuple::push_back.

\ingroup fcppttuple
*/
template <typename Tuple, typename NewElement>
using push_back_result = fcppt::tuple::detail::push_back_result<Tuple, NewElement>::type;
}

#endif
