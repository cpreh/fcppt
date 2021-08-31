//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_LABEL_IMPL_HPP_INCLUDED
#define FCPPT_RECORD_LABEL_IMPL_HPP_INCLUDED

#include <fcppt/record/element_init_impl.hpp>
#include <fcppt/record/label_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

// NOLINTNEXTLINE(cppcoreguidelines-c-copy-assignment-signature,misc-unconventional-assign-operator)
template <typename Tag>
template <typename Arg>
// NOLINTNEXTLINE(cppcoreguidelines-c-copy-assignment-signature,misc-unconventional-assign-operator)
fcppt::record::element_init<Tag, std::remove_cvref_t<Arg>>
fcppt::record::label<Tag>::operator=(Arg &&_arg)
{
  return fcppt::record::element_init<Tag, std::remove_cvref_t<Arg>>(
      std::forward<Arg>(_arg));
}

#endif
