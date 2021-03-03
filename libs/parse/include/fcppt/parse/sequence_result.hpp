//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SEQUENCE_RESULT_HPP_INCLUDED
#define FCPPT_PARSE_SEQUENCE_RESULT_HPP_INCLUDED

#include <fcppt/parse/detail/sequence_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief The result of a sequence parser.

\ingroup fcpptparse

Let V<T> for a type T be the function that adds a tuple type around T
if T is not a tuple already, or more formally:
<ul>
<li>If T is an #fcppt::tuple::object, then <code>V<T> = T</code>.</li>
<li>If T is not an #fcppt::tuple::object, then <code>V<T> = fcppt::tuple::object<T></code>.</li>
</ul>
The result type is computed as follows:
<ul>
<li>If \a Left is #fcppt::unit, then the result is \a Right.</li>
<li>If \a Right is #fcppt::unit, then the result is \a Left.</li>
<li>Now let <code>tuple<L_1,...,L_n></code> and <code>tuple<R_1,...,R_m></code>
be the results of applying V to \a Left and \a Right.
Then the result is <code>tuple<L_1,...,L_n,R_1,...,R_m></code>.
</li>
</ul>
*/
template <typename Left, typename Right>
using sequence_result =
    decltype(fcppt::parse::detail::sequence_result(std::declval<Left>(), std::declval<Right>()));

}
}

#endif
