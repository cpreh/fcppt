//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_IS_LAMBDA_HPP_INCLUDED
#define FCPPT_MPL_IS_LAMBDA_HPP_INCLUDED

#include <fcppt/mpl/lambda_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{
namespace detail
{
template <typename T>
struct is_lambda
{
  using type = std::false_type;
};

template <template <typename...> class T>
struct is_lambda<fcppt::mpl::lambda<T>>
{
  using type = std::true_type;
};
}
/**
\brief Checks if a type is a lambda.
\ingroup fcpptmpl

<code>T</code> is a lambda if an only if it is of the form
<code>fcppt::mpl::lambda<F></code> for some type <code>F</code>.
*/
template<typename T>
using is_lambda = typename fcppt::mpl::detail::is_lambda<T>::type;
}

#endif
