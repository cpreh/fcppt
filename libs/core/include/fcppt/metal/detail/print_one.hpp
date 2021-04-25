//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_DETAIL_PRINT_ONE_HPP_INCLUDED
#define FCPPT_METAL_DETAIL_PRINT_ONE_HPP_INCLUDED

#include <fcppt/type_name_from_info.hpp>
#include <fcppt/io/widen_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace metal
{
namespace detail
{
template <typename Type, typename Ch, typename Traits>
inline void print_one(std::basic_ostream<Ch, Traits> &_stream)
{
  _stream << fcppt::io::widen_string(fcppt::type_name_from_info(typeid(Type)));
}

}
}
}

#endif
