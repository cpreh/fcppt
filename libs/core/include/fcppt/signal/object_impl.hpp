//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_SIGNAL_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_SIGNAL_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/algorithm/fold.hpp>
#include <fcppt/signal/base_impl.hpp>
#include <fcppt/signal/object_decl.hpp>
#include <fcppt/signal/detail/enable_if_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename T, template <typename> class Base, typename Enable>
fcppt::signal::object<T, Base, Enable>::object(combiner_function &&_combiner)
    : combiner_(std::move(_combiner))
{
}

template <typename T, template <typename> class Base, typename Enable>
fcppt::signal::object<T, Base, Enable>::object(object &&) noexcept = default;

template <typename T, template <typename> class Base, typename Enable>
fcppt::signal::object<T, Base, Enable> &
fcppt::signal::object<T, Base, Enable>::operator=(object &&) noexcept = default;

template <typename T, template <typename> class Base, typename Enable>
fcppt::signal::object<T, Base, Enable>::~object<T, Base, Enable>() = default;

template <typename T, template <typename> class Base, typename Enable>
template <typename... Args>
typename fcppt::signal::object<T, Base, Enable>::result_type
fcppt::signal::object<T, Base, Enable>::operator()(initial_value &&_initial, Args &&..._args)
{
  return fcppt::algorithm::fold(
      base::connections(),
      std::move(_initial.get()),
      [this, &_args...](auto &_fcppt_item, result_type &&_fcppt_state) {
        return combiner_(std::move(_fcppt_state), _fcppt_item.function()(_args...));
      });
}

template <typename T, template <typename> class Base>
fcppt::signal::object<T, Base, fcppt::signal::detail::enable_if_void<T>>::object() = default;

template <typename T, template <typename> class Base>
fcppt::signal::object<T, Base, fcppt::signal::detail::enable_if_void<T>>::object(
    object &&) noexcept = default;

template <typename T, template <typename> class Base>
fcppt::signal::object<T, Base, fcppt::signal::detail::enable_if_void<T>> &
fcppt::signal::object<T, Base, fcppt::signal::detail::enable_if_void<T>>::operator=(
    object &&) noexcept = default;

template <typename T, template <typename> class Base>
fcppt::signal::object<T, Base, fcppt::signal::detail::enable_if_void<T>>::
    ~object<T, Base, fcppt::signal::detail::enable_if_void<T>>() = default;

template <typename T, template <typename> class Base>
template <typename... Args>
typename fcppt::signal::object<T, Base, fcppt::signal::detail::enable_if_void<T>>::result_type
fcppt::signal::object<T, Base, fcppt::signal::detail::enable_if_void<T>>::operator()(
    Args &&..._args)
{
  for (auto &item : base::connections())
  {
    item.function()(_args...);
  }
}

#endif
