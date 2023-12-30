//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_COM_DELETER_HPP_INCLUDED
#define FCPPT_COM_DELETER_HPP_INCLUDED

#include <fcppt/com_deleter_fwd.hpp> // IWYU pragma: keep

namespace fcppt
{
/**
\brief A deleter that uses the <code>Release</code> member function to destroy
an object.

\ingroup fcpptsmartptr

COM objects have a reference counting mechanism where calling
<code>Release</code> on them decrements the reference counter. This mechanism
is enabled by deriving from <code>IUnknown</code>
*/
struct com_deleter
{
  /**
  \brief Deletes a pointer using <code>Release</code>

  Calls <code>_ptr->Release()</code> if _ptr is not NULL

  \param _ptr The pointer to delete, can be NULL

  \tparam T Must derive from <code>IUnknown</code>
  */
  template <typename T>
  void operator()(T *const _ptr) const
  {
    if (_ptr)
    {
      _ptr->Release();
    }
  }
};

}

#endif
