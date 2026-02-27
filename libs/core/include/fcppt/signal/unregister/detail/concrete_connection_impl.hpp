//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_SIGNAL_UNREGISTER_DETAIL_CONCRETE_CONNECTION_IMPL_HPP_INCLUDED
#define FCPPT_SIGNAL_UNREGISTER_DETAIL_CONCRETE_CONNECTION_IMPL_HPP_INCLUDED

#include <fcppt/intrusive/base_impl.hpp> // IWYU pragma: keep
#include <fcppt/signal/connection_impl.hpp>
#include <fcppt/signal/unregister/function.hpp>
#include <fcppt/signal/unregister/detail/concrete_connection_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Function>
fcppt::signal::unregister::detail::concrete_connection<Function>::concrete_connection(
    list_type &_list, function_type &&_function, fcppt::signal::unregister::function &&_unregister)
    : fcppt::signal::connection{},
      base_type{_list},
      function_{std::move(_function)},
      unregister_(std::move(_unregister))
{
}

namespace fcppt::signal::unregister::detail
{
template <typename Function>
concrete_connection<Function>::~concrete_connection()
{
  this->unlink();

  try
  {
    this->unregister_();
  }
  catch (...)
  {
    std::terminate();
  }
}
}

template <typename Function>
fcppt::signal::unregister::detail::concrete_connection<Function>::function_type const &
fcppt::signal::unregister::detail::concrete_connection<Function>::function() const
{
  return function_;
}

#endif
