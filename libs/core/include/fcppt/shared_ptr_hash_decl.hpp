//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_SHARED_PTR_HASH_DECL_HPP_INCLUDED
#define FCPPT_SHARED_PTR_HASH_DECL_HPP_INCLUDED

#include <fcppt/shared_ptr_fwd.hpp>
#include <fcppt/shared_ptr_hash_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief A hash for fcppt::shared_ptr that hashes pointers

\ingroup fcpptsmartptr
*/
template <typename Type>
struct shared_ptr_hash<fcppt::shared_ptr<Type>>
{
  using type = fcppt::shared_ptr<Type>;

  std::size_t operator()(type const &) const noexcept;
};

}

#endif
