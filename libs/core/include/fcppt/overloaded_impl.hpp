//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OVERLOADED_IMPL_HPP_INCLUDED
#define FCPPT_OVERLOADED_IMPL_HPP_INCLUDED

#include <fcppt/overloaded_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename... Types>
template <typename... Args>
fcppt::overloaded<Types...>::overloaded(Args &&..._args) : Types{std::forward<Args>(_args)}...
{
}

#endif
