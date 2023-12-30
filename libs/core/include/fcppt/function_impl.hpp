//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_FUNCTION_IMPL_HPP_INCLUDED
#define FCPPT_FUNCTION_IMPL_HPP_INCLUDED

#include <fcppt/function_fwd.hpp> // IWYU pragma: export
#include <fcppt/function_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ret, typename... Args>
template <typename F>
fcppt::function<Ret(Args...)>::function(F _function) : impl_{_function}
{
}

template <typename Ret, typename... Args>
template <typename F, typename Alloc>
fcppt::function<Ret(Args...)>::function(
    std::allocator_arg_t const _allocator_arg, Alloc const &_alloc, F _function)
    : impl_(_allocator_arg, _alloc, _function)
{
}

template <typename Ret, typename... Args>
Ret fcppt::function<Ret(Args...)>::operator()(Args... _args) const
{
  return impl_(std::forward<Args>(_args)...);
}

#endif
