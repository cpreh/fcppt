//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_SIGNAL_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_SIGNAL_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/algorithm/fold.hpp>
#include <fcppt/signal/base_impl.hpp>
#include <fcppt/signal/object_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Result, typename... Args, template <typename> class Base>
fcppt::signal::object<Result(Args...), Base>::object(combiner_function &&_combiner)
    : combiner_(std::move(_combiner))
{
}

template <typename Result, typename... Args, template <typename> class Base>
fcppt::signal::object<Result(Args...), Base>::object(object &&) noexcept = default;

template <typename Result, typename... Args, template <typename> class Base>
fcppt::signal::object<Result(Args...), Base> &
fcppt::signal::object<Result(Args...), Base>::operator=(object &&) noexcept = default;

namespace fcppt::signal
{
template <typename Result, typename... Args, template <typename> class Base>
object<Result(Args...), Base>::~object() = default;
}

template <typename Result, typename... Args, template <typename> class Base>
Result
fcppt::signal::object<Result(Args...), Base>::operator()(initial_value &&_initial, Args... _args)
{
  return fcppt::algorithm::fold(
      base::connections(),
      std::move(_initial.get()),
      [this, &_args...](auto &_fcppt_item, result_type &&_fcppt_state)
      { return combiner_(std::move(_fcppt_state), _fcppt_item.function()(_args...)); });
}

template <typename... Args, template <typename> class Base>
fcppt::signal::object<void(Args...), Base>::object() = default;

template <typename... Args, template <typename> class Base>
fcppt::signal::object<void(Args...), Base>::object(object &&) noexcept = default;

template <typename... Args, template <typename> class Base>
fcppt::signal::object<void(Args...), Base> &
fcppt::signal::object<void(Args...), Base>::operator=(object &&) noexcept = default;

namespace fcppt::signal
{
template <typename... Args, template <typename> class Base>
object<void(Args...), Base>::~object() = default;
}

template <typename... Args, template <typename> class Base>
void fcppt::signal::object<void(Args...), Base>::operator()(Args ..._args)
{
  for (auto &item : base::connections())
  {
    item.function()(_args...);
  }
}

#endif
