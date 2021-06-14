//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_MONAD_HPP_INCLUDED
#define FCPPT_EITHER_MONAD_HPP_INCLUDED

#include <fcppt/concepts/invocable_move.hpp>
#include <fcppt/concepts/move_constructible.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/either/object_concept.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/success_move_type.hpp>
#include <fcppt/either/success_type.hpp>
#include <fcppt/monad/instance_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::monad
{
template <typename Failure, typename Success>
struct instance<fcppt::either::object<Failure, Success>>
{
  template <fcppt::concepts::move_constructible Type>
  struct constructor
  {
    using type = fcppt::either::object<Failure, Type>;
  };

  template <fcppt::either::object_concept Either>
  struct inner_type
  {
    using type = fcppt::either::success_type<Either>;
  };

  template <fcppt::concepts::move_constructible Value>
  [[nodiscard]] static auto return_(Value &&_value)
  {
    return fcppt::either::make_success<Failure>(std::forward<Value>(_value));
  }

  template <
      fcppt::either::object_concept Either,
      fcppt::concepts::invocable_move<fcppt::either::success_move_type<Either>> Function>
  [[nodiscard]] static auto
  bind(Either &&_either, Function const &_function) requires fcppt::either::object_concept<
      std::invoke_result_t<Function, fcppt::either::success_move_type<Either>>>

  {
    return fcppt::either::bind(std::forward<Either>(_either), _function);
  }
};

}

#endif
