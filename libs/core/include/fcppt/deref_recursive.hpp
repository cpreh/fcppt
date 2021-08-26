//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DEREF_RECURSIVE_HPP_INCLUDED
#define FCPPT_DEREF_RECURSIVE_HPP_INCLUDED

#include <fcppt/deref.hpp>
#include <fcppt/deref_impl_fwd.hpp>
#include <fcppt/is_recursive.hpp>
#include <fcppt/recursive_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
template <typename Arg>
struct deref_impl<Arg, std::enable_if_t<fcppt::is_recursive<std::remove_const_t<Arg>>::value>>
{
  static auto execute(Arg &_value) -> decltype(fcppt::deref(_value.get()))
  {
    return fcppt::deref(_value.get());
  }
};

}

#endif
