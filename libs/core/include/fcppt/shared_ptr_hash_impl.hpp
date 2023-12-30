//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_SHARED_PTR_HASH_IMPL_HPP_INCLUDED
#define FCPPT_SHARED_PTR_HASH_IMPL_HPP_INCLUDED

#include <fcppt/shared_ptr_hash_decl.hpp> // IWYU pragma: export
#include <fcppt/shared_ptr_hash_fwd.hpp> // IWYU pragma: export
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <fcppt/config/external_end.hpp>

template <typename Type>
std::size_t
fcppt::shared_ptr_hash<fcppt::shared_ptr<Type>>::operator()(type const &_value) const noexcept
{
  return std::hash<Type *>()(_value.get_pointer());
}

#endif
