//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_REFERENCE_COMPARISON_HPP_INCLUDED
#define FCPPT_REFERENCE_COMPARISON_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Compares two references for equality

\ingroup fcpptref

Compares \a _a and \a _b for equality. Two references are equal if they
refer to the same object.

\param _a The first reference
\param _b The second reference
*/
template <typename T>
bool operator==(fcppt::reference<T> const &_a, fcppt::reference<T> const &_b) noexcept
{
  return &_a.get() == &_b.get();
}

/**
\brief Compares two references for inequality

\ingroup fcpptref

Compares \a _a and \a _b for inequality. Equal to <code>!(_a == _b)</code>.

\param _a The first reference
\param _b The second reference
*/
template <typename T>
bool operator!=(fcppt::reference<T> const &_a, fcppt::reference<T> const &_b) noexcept
{
  return !(_a == _b);
}

/**
\brief Compares two references lexicographically

\ingroup fcpptref

Compares \a _a and \a _b lexicographically by comparing the stored pointers via
<code>std::less</code>.

\param _a The first reference
\param _b The second reference
*/
template <typename T>
bool operator<(fcppt::reference<T> const &_a, fcppt::reference<T> const &_b) noexcept
{
  return std::less<T *>()(&_a.get(), &_b.get());
}

}

#endif
