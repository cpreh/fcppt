//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_MONAD_HPP_INCLUDED
#define FCPPT_OPTIONAL_MONAD_HPP_INCLUDED

#include <fcppt/monad/instance_fwd.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace monad
{
template <typename Arg>
struct instance<fcppt::optional::object<Arg>>
{
  template <typename Type>
  struct constructor
  {
    using type = fcppt::optional::object<Type>;
  };

  template <typename Optional>
  struct inner_type
  {
    using type = fcppt::optional::value_type<Optional>;
  };

  template <typename Value>
  static auto return_(Value &&_value)
  {
    return fcppt::optional::make(std::forward<Value>(_value));
  }

  template <typename Optional, typename Function>
  static auto bind(Optional &&_optional, Function const &_function)
  {
    return fcppt::optional::bind(std::forward<Optional>(_optional), _function);
  }
};

}
}

#endif
