//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_FROM_POINTER_HPP_INCLUDED
#define FCPPT_OPTIONAL_FROM_POINTER_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/optional/reference.hpp>

namespace fcppt::optional
{
/**
\brief Creates an optional reference from a pointer

\ingroup fcpptoptional

Creates an optional reference from \a _pointer. If \a _pointer is the null
pointer, the result will be empty. Otherwise, the result will contain a
reference to <code>*_pointer</code>.
*/
template <typename T>
[[nodiscard]] fcppt::optional::reference<T> from_pointer(T *const _pointer)
{
  using result_type = fcppt::optional::reference<T>;

  return _pointer != nullptr ? result_type{fcppt::make_ref(*_pointer)} : result_type{};
}

}

#endif
