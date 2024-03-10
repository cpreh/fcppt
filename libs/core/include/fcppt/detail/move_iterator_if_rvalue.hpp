//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DETAIL_MOVE_ITERATOR_IF_RVALUE_HPP_INCLUDED
#define FCPPT_DETAIL_MOVE_ITERATOR_IF_RVALUE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::detail
{
template <typename Type, typename Iterator>
inline Iterator move_iterator_if_rvalue(Iterator const &_iterator)
  requires(std::is_lvalue_reference_v<Type>)
{
  return _iterator;
}

template <typename Type, typename Iterator>
inline decltype(std::make_move_iterator(std::declval<Iterator const &>()))
move_iterator_if_rvalue(Iterator const &_iterator)
  requires(!std::is_lvalue_reference_v<Type>)
{
  return std::make_move_iterator(_iterator);
}
}

#endif
