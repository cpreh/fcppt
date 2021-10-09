//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_RAW_VECTOR_OUTPUT_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_OUTPUT_HPP_INCLUDED

#include <fcppt/container/output.hpp>
#include <fcppt/container/raw_vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::raw_vector
{
/**
\brief Outputs a raw vector to a stream.

\ingroup fcpptcontainerraw_vector
*/
template <typename Ch, typename Traits, typename Type, typename Alloc>
std::basic_ostream<Ch, Traits> &operator<<(
    std::basic_ostream<Ch, Traits> &_stream,
    fcppt::container::raw_vector::object<Type, Alloc> const &_vector)
{
  return _stream << fcppt::container::output(_vector);
}
}

#endif
