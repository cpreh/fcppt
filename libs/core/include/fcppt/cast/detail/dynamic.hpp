//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_DETAIL_DYNAMIC_HPP_INCLUDED
#define FCPPT_CAST_DETAIL_DYNAMIC_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/optional/reference.hpp>

namespace fcppt::cast::detail
{
template <typename Derived, typename Base>
fcppt::optional::reference<Derived> dynamic(Base &_base) noexcept
{
  Derived *const derived_ptr{dynamic_cast<Derived *>(&_base)};

  using result_type = fcppt::optional::reference<Derived>;

  return derived_ptr != nullptr ? result_type{fcppt::make_ref(*derived_ptr)} : result_type{};
}

}

#endif
