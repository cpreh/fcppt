//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_BASE_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_BASE_IMPL_HPP_INCLUDED

#include <fcppt/options/base_decl.hpp> // IWYU pragma: export

template <typename Result>
fcppt::options::base<Result>::base() = default;

namespace fcppt::options
{
template <typename Result>
base<Result>::~base() = default;
}

#endif
