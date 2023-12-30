//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_ELEMENT_INIT_IMPL_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_INIT_IMPL_HPP_INCLUDED

#include <fcppt/record/element_init_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Tag, typename Type>
fcppt::record::element_init<Tag, Type>::element_init(value_type _value)
    : value_(std::move(_value))
{
}

template <typename Tag, typename Type>
typename fcppt::record::element_init<Tag, Type>::value_type &
fcppt::record::element_init<Tag, Type>::value()
{
  return this->value_;
}

#endif
