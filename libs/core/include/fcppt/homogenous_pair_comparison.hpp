//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_HOMOGENOUS_PAIR_COMPARISON_HPP_INCLUDED
#define FCPPT_HOMOGENOUS_PAIR_COMPARISON_HPP_INCLUDED

#include <fcppt/homogenous_pair_impl.hpp>

namespace fcppt
{
/**
\brief Compares two homogenous pairs lexicographically

\ingroup fcpptvarious

Compares the two pairs \a _left and \a _right lexicographically.  If
<code>_left.first</code> and <code>_right.first</code> are equal, which is
tested by using <code>!(_left.first < _right.first) && !(_right.first <
_left.first)</code> then the result is <code>_left.second <
_right.second</code>, otherwise the result is <code>_left.first <
_right.first</code>.

\param _left The left operand

\param _right The right operand

\return If \a _left is lexicographically less than \a _right
*/
template <typename T>
bool operator<(fcppt::homogenous_pair<T> const &_left, fcppt::homogenous_pair<T> const &_right)
{
  if (_left.first < _right.first)
  {
    return true;
  }
  if (_right.first < _left.first)
  {
    return false;
  }

  return _left.second < _right.second;
}

/**
\brief Compares two homogenous pairs for equality

\ingroup fcpptvarious

Compares the two pairs \a _left and \a _right for equality, using
<code>_left.first == _right.first && _left.second == _right.second</code>.

\param _left The left operand

\param _right The right operand

\return If both pairs are equal
*/
template <typename T>
inline bool
operator==(fcppt::homogenous_pair<T> const &_left, fcppt::homogenous_pair<T> const &_right)
{
  return _left.first == _right.first && _left.second == _right.second;
}

/**
\brief Compares two homogenous pairs for equality

\ingroup fcpptvarious

Compares the two pairs \a _left and \a _right for equality, using
<code>!(_left == _right)</code>.

\param _left The left operand

\param _right The right operand

\return If both pairs are not equal
*/
template <typename T>
inline bool
operator!=(fcppt::homogenous_pair<T> const &_left, fcppt::homogenous_pair<T> const &_right)
{
  return !(_left == _right);
}

}

#endif
