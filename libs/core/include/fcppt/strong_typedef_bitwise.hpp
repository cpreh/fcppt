//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_STRONG_TYPEDEF_BITWISE_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_BITWISE_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>

namespace fcppt
{
/**
\brief Bitwise and.

\ingroup fcpptstrongtypedef
*/
template <typename T, typename Tag>
inline fcppt::strong_typedef<T, Tag>
operator&(fcppt::strong_typedef<T, Tag> const &_left, fcppt::strong_typedef<T, Tag> const &_right)
{
  return fcppt::strong_typedef<T, Tag>{_left.get() & _right.get()};
}

/**
\brief Bitwise or.

\ingroup fcpptstrongtypedef
*/
template <typename T, typename Tag>
inline fcppt::strong_typedef<T, Tag>
operator|(fcppt::strong_typedef<T, Tag> const &_left, fcppt::strong_typedef<T, Tag> const &_right)
{
  return fcppt::strong_typedef<T, Tag>{_left.get() | _right.get()};
}

/**
\brief Bitwise xor.

\ingroup fcpptstrongtypedef
*/
template <typename T, typename Tag>
inline fcppt::strong_typedef<T, Tag>
operator^(fcppt::strong_typedef<T, Tag> const &_left, fcppt::strong_typedef<T, Tag> const &_right)
{
  return fcppt::strong_typedef<T, Tag>{_left.get() ^ _right.get()};
}

/**
\brief Bitwise negation.

\ingroup fcpptstrongtypedef
*/
template <typename T, typename Tag>
inline fcppt::strong_typedef<T, Tag> operator~(fcppt::strong_typedef<T, Tag> const &_value)
{
  return fcppt::strong_typedef<T, Tag>{~_value.get()};
}

}

#endif
