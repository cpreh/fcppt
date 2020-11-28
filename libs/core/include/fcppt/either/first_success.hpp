//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_FIRST_SUCCESS_HPP_INCLUDED
#define FCPPT_EITHER_FIRST_SUCCESS_HPP_INCLUDED

#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/success_type.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace either
{
/**
\brief Call a container of functions, returning their first success or a
container of failures

\ingroup fcppteither

For <code>_functions = (f_1,...,f_n)</code>, let <code>i</code> be the smallest
index such that <code>f_i()</code> returns success <code>s</code>, in which
case the result is <code>s</code>. If there is no such index, then all
functions return failures <code>e_1,...,e_n</code> and the result is
<code>(e_1,...,_e_n)</code>.

\tparam Functions A container of functions callable as
<code>fcppt::either::object<F,S> ()</code>
*/
template <typename Functions>
fcppt::either::object<
    std::vector<
        fcppt::either::failure_type<std::result_of_t<fcppt::type_traits::value_type<Functions>()>>>,
    fcppt::either::success_type<std::result_of_t<fcppt::type_traits::value_type<Functions>()>>>
first_success(Functions const &_functions)
{
  using failure_container = std::vector<
      fcppt::either::failure_type<std::result_of_t<fcppt::type_traits::value_type<Functions>()>>>;

  using result_type = fcppt::either::object<
      failure_container,
      fcppt::either::success_type<std::result_of_t<fcppt::type_traits::value_type<Functions>()>>>;

  failure_container failures{};

  for (fcppt::type_traits::value_type<Functions> const &function : _functions)
  {
    auto result(function());

    if (result.has_success())
    {
      return result_type{std::move(result.get_success_unsafe())};
    }

    failures.push_back(std::move(result.get_failure_unsafe()));
  }

  return result_type{std::move(failures)};
}

}
}

#endif
