//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_REFERENCE_HASH_DECL_HPP_INCLUDED
#define FCPPT_REFERENCE_HASH_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/reference_hash_fwd.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief A hash for fcppt::reference that hashes pointers

\ingroup fcpptref
*/
template <typename Type>
struct reference_hash<fcppt::reference<Type>>
{
  using type = fcppt::reference<Type>;

  std::size_t operator()(type const &) const noexcept;
};

}

#endif
