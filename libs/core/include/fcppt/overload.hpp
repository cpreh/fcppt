//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OVERLOAD_HPP_INCLUDED
#define FCPPT_OVERLOAD_HPP_INCLUDED

#include <fcppt/overloaded_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Creates an overloaded lambda.

\ingroup fcpptvarious
*/
template <typename... Args>
fcppt::overloaded<fcppt::type_traits::remove_cv_ref_t<Args>...> overload(Args &&..._args)
{
  return fcppt::overloaded<fcppt::type_traits::remove_cv_ref_t<Args>...>{
      std::forward<Args>(_args)...};
}

}

#endif
