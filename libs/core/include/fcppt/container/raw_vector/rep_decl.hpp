//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_RAW_VECTOR_REP_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_REP_DECL_HPP_INCLUDED

#include <fcppt/container/raw_vector/rep_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::raw_vector
{
/**
\brief The representation of a raw vector.

\ingroup fcpptcontainerraw_vector

Can be used to initialize a raw vector by taking ownership of the memory from another container.

\tparam A The allocator type.
*/
template <typename A>
class rep
{
public:
  using pointer = typename std::allocator_traits<A>::pointer;

  rep(A const &, pointer first, pointer last, pointer cap) noexcept;

  [[nodiscard]] A const &alloc() const noexcept;

  [[nodiscard]] pointer first() const noexcept;

  [[nodiscard]] pointer last() const noexcept;

  [[nodiscard]] pointer cap() const noexcept;

private:
  A alloc_;

  pointer first_;

  pointer last_;

  pointer cap_;
};

}

#endif
