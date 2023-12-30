//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_STREAM_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_STREAM_IMPL_HPP_INCLUDED

#include <fcppt/parse/basic_stream_decl.hpp> // IWYU pragma: export

template <typename Ch>
fcppt::parse::basic_stream<Ch>::basic_stream() = default;

namespace fcppt::parse
{
template <typename Ch>
basic_stream<Ch>::~basic_stream() = default;
}

#endif
