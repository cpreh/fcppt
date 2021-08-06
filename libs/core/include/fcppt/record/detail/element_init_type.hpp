//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_ELEMENT_INIT_TYPE_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_ELEMENT_INIT_TYPE_HPP_INCLUDED

#include <fcppt/record/detail/element_init_fwd.hpp>


namespace fcppt::record::detail
{
template <typename Type>
struct element_init_type_impl;

template <typename Tag, typename Type>
struct element_init_type_impl<fcppt::record::detail::element_init<Tag, Type>>
{
  using type = Type;
};

template <typename Type>
using element_init_type = typename fcppt::record::detail::element_init_type_impl<Type>::type;

}

#endif
