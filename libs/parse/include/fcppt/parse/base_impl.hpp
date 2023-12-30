//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASE_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASE_IMPL_HPP_INCLUDED

#include <fcppt/parse/base_decl.hpp> // IWYU pragma: export

template <typename Result, typename Ch, typename Skipper>
fcppt::parse::base<Result, Ch, Skipper>::base() = default;

namespace fcppt::parse
{
template <typename Result, typename Ch, typename Skipper>
base<Result, Ch, Skipper>::~base() = default;
}

#endif
