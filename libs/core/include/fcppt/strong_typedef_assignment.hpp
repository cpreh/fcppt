//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_STRONG_TYPEDEF_ASSIGNMENT_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_ASSIGNMENT_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>

namespace fcppt
{
/**
\brief Add and assign operator.

\ingroup fcpptstrongtypedef
*/
template <typename T, typename Tag>
inline fcppt::strong_typedef<T, Tag> &
operator+=(fcppt::strong_typedef<T, Tag> &_left, fcppt::strong_typedef<T, Tag> const &_right)
{
  _left.get() += _right.get();

  return _left;
}

/**
\brief Subtract and assign operator.

\ingroup fcpptstrongtypedef
*/
template <typename T, typename Tag>
inline fcppt::strong_typedef<T, Tag> &
operator-=(fcppt::strong_typedef<T, Tag> &_left, fcppt::strong_typedef<T, Tag> const &_right)
{
  _left.get() -= _right.get();

  return _left;
}

/**
\brief Multiply and assign operator.

\ingroup fcpptstrongtypedef
*/
template <typename T, typename Tag>
inline fcppt::strong_typedef<T, Tag> &
operator*=(fcppt::strong_typedef<T, Tag> &_left, fcppt::strong_typedef<T, Tag> const &_right)
{
  _left.get() *= _right.get();

  return _left;
}

/**
\brief Bitwise and and assign operator.

\ingroup fcpptstrongtypedef
*/
template <typename T, typename Tag>
inline fcppt::strong_typedef<T, Tag> &
operator&=(fcppt::strong_typedef<T, Tag> &_left, fcppt::strong_typedef<T, Tag> const &_right)
{
  _left.get() &= _right.get();

  return _left;
}

/**
\brief Bitwise or and assign operator.

\ingroup fcpptstrongtypedef
*/
template <typename T, typename Tag>
inline fcppt::strong_typedef<T, Tag> &
operator|=(fcppt::strong_typedef<T, Tag> &_left, fcppt::strong_typedef<T, Tag> const &_right)
{
  _left.get() |= _right.get();

  return _left;
}

/**
\brief Bitwise xor and assign operator.

\ingroup fcpptstrongtypedef
*/
template <typename T, typename Tag>
inline fcppt::strong_typedef<T, Tag> &
operator^=(fcppt::strong_typedef<T, Tag> &_left, fcppt::strong_typedef<T, Tag> const &_right)
{
  _left.get() ^= _right.get();

  return _left;
}

}

#endif
