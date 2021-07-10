//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_MAP_MULTI_HPP_INCLUDED
#define FCPPT_MPL_LIST_MAP_MULTI_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/lambda_concept.hpp>
#include <fcppt/mpl/list/apply.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/transpose.hpp>

namespace fcppt::mpl::list
{
/**
\brief Applies an n-ary lambda to every element-tuple of n lists.
\ingroup fcpptmpl
If <code>Lists=list::object<L_{1,1},...,L_{1,k}>, ... list::object<L_{1,n},...,L_{n,k}></code> and
<code>L</code> holds a function <code>F</code> of arity <code>n</code>,
then the result is
\code
list::object<F<L_{1,1},...,L_{1,n}>,...,F<L_{1,k},...,L_{n,k}>>
\endcode
\tparam Lists Must all have the same size.
// TODO(concepts)
*/
template <fcppt::mpl::lambda_concept F, fcppt::mpl::list::object_concept... Lists>
using map_multi = fcppt::mpl::list::map<
    fcppt::mpl::list::transpose<fcppt::mpl::list::object<Lists...>>,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::list::apply>,
        fcppt::mpl::constant<F>,
        fcppt::mpl::arg<1>>>;
}

#endif
