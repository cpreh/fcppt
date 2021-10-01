//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_SIGNAL_BASE_DECL_HPP_INCLUDED
#define FCPPT_SIGNAL_BASE_DECL_HPP_INCLUDED

#include <fcppt/function.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/intrusive/list_decl.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>
#include <fcppt/signal/base_fwd.hpp>
#include <fcppt/signal/detail/concrete_connection_fwd.hpp>

namespace fcppt::signal
{
/**
\brief Default base class for signals. Provides no unlinking capabilities.
\tparam T The signal's function type
\ingroup fcpptsignal

See \ref fcpptsignal for more information.
*/
template <typename T>
class base
{
public:
  FCPPT_NONCOPYABLE(base);

  /**
  \brief A typedef for the function's return type
  */
  using function_signature = T;

  /**
  \brief A typedef for the wrapped function
  */
  using function = fcppt::function<T>;

  /**
  \brief Connect a callback to this signal
  */
  fcppt::signal::auto_connection connect(function &&);

  /**
  \brief Return if the signal has connections attached to it.
  */
  bool empty() const;

protected:
  using concrete_connection = fcppt::signal::detail::concrete_connection<function_signature>;

  using connection_list = fcppt::intrusive::list<concrete_connection>;

  base();

  base(base &&) noexcept;

  base &operator=(base &&) noexcept;

  ~base();

  connection_list &connections() const;

private:
  mutable connection_list connections_;
};

}

#endif
