//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DEFAULT_DELETER_HPP_INCLUDED
#define FCPPT_DEFAULT_DELETER_HPP_INCLUDED

#include <fcppt/assert_complete.hpp>
#include <fcppt/default_deleter_fwd.hpp> // IWYU pragma: keep
#include <fcppt/preprocessor/disable_gnu_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace fcppt
{
/**
\brief A deleter that uses <code>delete</code> to destroy an object.

\ingroup fcpptsmartptr
*/
struct default_deleter
{
  /**
  \brief Deletes the object using <code>delete</code>

  \tparam T Must be a complete type
  */
  template <typename T>
  void operator()(T const *_ptr) const
  {
    FCPPT_ASSERT_COMPLETE(T);

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GNU_GCC_WARNING(-Wfree-nonheap-object)
    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
    delete _ptr;
FCPPT_PP_POP_WARNING
  }
};

}

#endif
