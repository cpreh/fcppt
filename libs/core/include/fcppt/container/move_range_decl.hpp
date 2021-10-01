//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_MOVE_RANGE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_MOVE_RANGE_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/container/move_range_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container
{
/**
\brief A range that moves its elements

\ingroup fcpptcontainer

\tparam Container A container type.
*/
template <typename Container>
class move_range
{
  FCPPT_NONCOPYABLE(move_range);

public:
  explicit move_range(Container &&);

  move_range(move_range &&) noexcept;

  move_range &operator=(move_range &&) noexcept;

  ~move_range();

  using iterator = std::move_iterator<typename Container::iterator>;

  using const_iterator = typename Container::const_iterator;

  [[nodiscard]] iterator begin();

  [[nodiscard]] iterator end();

  [[nodiscard]] const_iterator begin() const;

  [[nodiscard]] const_iterator end() const;

private:
  Container container_;
};

}

#endif
