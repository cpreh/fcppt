//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_ALTERNATIVE_RESULT_HPP_INCLUDED
#define FCPPT_PARSE_ALTERNATIVE_RESULT_HPP_INCLUDED

#include <fcppt/mpl/list/append.hpp>
#include <fcppt/mpl/list/unique.hpp>
#include <fcppt/parse/detail/alternative_list.hpp>
#include <fcppt/parse/detail/alternative_result.hpp>
#include <fcppt/variant/object_fwd.hpp>

namespace fcppt::parse
{
/**
\brief The result type of an alternative parser.

\ingroup fcpptparse

Let V<T> for a type T be the function that adds a variant type around T
if T is not a variant already, or more formally:
<ul>
<li>If T is an #fcppt::variant::object, then <code>V<T> = T</code>.</li>
<li>If T is not an #fcppt::variant::object, then <code>V<T> = fcppt::variant::object<T></code>.</li>
</ul>
Let <code>variant<L_1,...,L_n></code> and <code>variant<R_1,...,R_m></code>
be the results of applying V to \a Left and \a Right.
<ul>
<li>If n+m=1 and m=0, then <code>alternative_result<Left,Right></code> is L_1.</li>
<li>If n+m=1 and n=0, then <code>alternative_result<Left,Right></code> is R_1.</li>
<li>If n+m>1, then alternative_result<Left,Right> is <code>variant<L_1,...,L_n,R_1,...,R_m></code>.</li>
</ul>
*/
template <typename Left, typename Right>
using alternative_result =
    fcppt::parse::detail::alternative_result<fcppt::mpl::list::unique<fcppt::mpl::list::append<
        fcppt::parse::detail::alternative_list<Left>,
        fcppt::parse::detail::alternative_list<Right>>>>;
}

#endif
