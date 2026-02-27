//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_INDEX_MAP_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_INDEX_MAP_DECL_HPP_INCLUDED

#include <fcppt/function_fwd.hpp>
#include <fcppt/container/index_map_fwd.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container
{
/**
\brief An index-based container that grows on demand.

\ingroup fcpptcontainer

This container is a wrapper around a vector that grows on demand. If the
container is accessed with an out-of-bounds index, it inserts a new element
first. This is most useful with #fcppt::optional::object.

\tparam T The element type.

\tparam A The allocator type.
*/
template <typename T, typename A>
class index_map
{
public:
  using internal_type = std::vector<T, A>;

  using size_type = internal_type::size_type;

  using reference = internal_type::reference;

  index_map();

  using insert_function = fcppt::function<T()>;

  /**
  \brief Returns the element at an index or inserts new ones using a function.

  Returns the element at \a index. If there is no such element, the
  result of <code>insert()</code> is inserted. Note that \a insert might
  be called multiple times.
  */
  [[nodiscard]] reference get(size_type index, insert_function const &insert);

  /**
  \brief Returns the element at an index or inserts new default-constructed one.

  Returns the element at \a index. If there is no such element,
  <code>T()</code> is inserted.
  */
  [[nodiscard]] reference operator[](size_type index);

  [[nodiscard]] internal_type const &impl() const;

private:
  internal_type impl_;
};

}

#endif
