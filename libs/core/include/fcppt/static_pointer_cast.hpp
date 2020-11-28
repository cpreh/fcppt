//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_STATIC_POINTER_CAST_HPP_INCLUDED
#define FCPPT_STATIC_POINTER_CAST_HPP_INCLUDED

#include <fcppt/shared_ptr_impl.hpp>

namespace fcppt
{
/**
\brief Casts an #fcppt::shared_ptr  using
<code>static_cast</code>

\ingroup fcpptsmartptr

Casts the pointer stored in \a _ptr to type <code>U *</code> using
<code>static_cast</code>.

\tparam Dest The type of the destination shared_ptr

\tparam Source The type of the source shared_ptr

\param _ptr The source shared_ptr

\return The converted shared_ptr

\warning The behaviour is undefined if the <code>static_cast</code> is not well
formed.
*/
template <typename Dest, typename Source>
fcppt::shared_ptr<Dest> static_pointer_cast(fcppt::shared_ptr<Source> const &_ptr)
{
  return fcppt::shared_ptr<Dest>(_ptr, static_cast<Dest *>(_ptr.get_pointer()));
}

}

#endif
