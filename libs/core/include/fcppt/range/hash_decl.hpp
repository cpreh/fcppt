//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANGE_HASH_DECL_HPP_INCLUDED
#define FCPPT_RANGE_HASH_DECL_HPP_INCLUDED

#include <fcppt/range/hash_fwd.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt::range
{
/**
\brief Hashes a range.

\ingroup fcpptrange

This is a naive implementation for hashing a range that combines individual
hashes of the elements in the range.

\tparam Type Must be supported by std::hash.
*/
template <typename Type>
struct hash
{
  std::size_t operator()(Type const &) const;
};

}

#endif
