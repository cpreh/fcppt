//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_DETAIL_PRINT_ONE_HPP_INCLUDED
#define FCPPT_METAL_DETAIL_PRINT_ONE_HPP_INCLUDED

#include <fcppt/type_name_from_info.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/io/widen_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace metal
{
namespace detail
{
template <typename Type>
inline void print_one(fcppt::io::ostream &_stream)
{
  _stream << fcppt::io::widen_string(fcppt::type_name_from_info(typeid(Type)));
}

}
}
}

#endif
