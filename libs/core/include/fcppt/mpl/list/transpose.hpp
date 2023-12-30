//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_TRANSPOSE_HPP_INCLUDED
#define FCPPT_MPL_LIST_TRANSPOSE_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/size_type_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/at.hpp>
#include <fcppt/mpl/list/indices.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep

namespace fcppt::mpl::list
{
namespace detail
{
namespace transpose_impl
{
template<fcppt::mpl::size_type_concept Index, fcppt::mpl::list::object_concept... Lists>
using elements_at = fcppt::mpl::list::object<fcppt::mpl::list::at<Lists,Index>...>;
}

template<fcppt::mpl::list::object_concept List>
struct transpose;

template <fcppt::mpl::list::object_concept List, fcppt::mpl::list::object_concept... Lists>
struct transpose<fcppt::mpl::list::object<List,Lists...>>
{
  using type = fcppt::mpl::list::map<
      fcppt::mpl::list::indices<List>,
      fcppt::mpl::bind<
          fcppt::mpl::lambda<detail::transpose_impl::elements_at>,
          fcppt::mpl::arg<1>,
          fcppt::mpl::constant<List>,
          fcppt::mpl::constant<Lists>...>>;
};
}
/**
\brief Transposes n lists of length k into k lists of length n.
\ingroup fcpptmpl
If
\code
List=list::object<list::object<L_{1,1},...,L_{1,k}>, ... list::object<L_{1,n},...,L_{n,k}>>
\endcode
then the result is
\code
list::object<list::object<L_{1,1},...,L_{1,n}>,...,list::object<L_{1,k},...,L_{n,k}>>
\endcode
// TODO(concepts)
*/
template <fcppt::mpl::list::object_concept List>
using transpose = typename fcppt::mpl::list::detail::transpose<List>::type;
}

#endif
