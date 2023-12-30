//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_FUNCTION_DECL_HPP_INCLUDED
#define FCPPT_FUNCTION_DECL_HPP_INCLUDED

#include <fcppt/function_fwd.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <memory>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief A function object that cannot be null

\ingroup fcpptvarious

This class is like <code>%std::function</code>, except it cannot be null and
its constructor is explicit.
*/
template <typename Ret, typename... Args>
class function<Ret(Args...)>
{
public:
  using result_type = Ret;

  template <typename F>
  explicit function(F);

  template <typename F, typename Alloc>
  function(std::allocator_arg_t, Alloc const &, F);

  Ret operator()(Args...) const;

private:
  std::function<Ret(Args...)> impl_;
};

}

#endif
