//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_ELEMENT_INIT_TYPE_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_INIT_TYPE_HPP_INCLUDED

#include <fcppt/record/element_init_fwd.hpp>


namespace fcppt::record
{
namespace detail
{
template <typename Type>
struct element_init_type;

template <typename Tag, typename Type>
struct element_init_type<fcppt::record::element_init<Tag, Type>>
{
  using type = Type;
};
}

/**
\brief The value type of #fcppt::record::element_init
\ingroup fcpptrecord
*/
template <typename Type>
using element_init_type = typename fcppt::record::detail::element_init_type<Type>::type;
}

#endif
