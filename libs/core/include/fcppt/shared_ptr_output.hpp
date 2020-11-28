//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_SHARED_PTR_OUTPUT_HPP_INCLUDED
#define FCPPT_SHARED_PTR_OUTPUT_HPP_INCLUDED

#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Outputs a shared pointer

\ingroup fcpptsmartptr

Outputs \a _ptr to \a _stream.

\return \a stream
*/
template <typename Ch, typename Traits, typename Type, typename Deleter>
inline std::basic_ostream<Ch, Traits> &
operator<<(std::basic_ostream<Ch, Traits> &_stream, fcppt::shared_ptr<Type, Deleter> const &_ptr)
{
  return _stream << _ptr.get_pointer();
}

}

#endif
