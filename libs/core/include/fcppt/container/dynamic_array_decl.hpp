//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_DYNAMIC_ARRAY_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_DYNAMIC_ARRAY_DECL_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/container/dynamic_array_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
/**
\brief An array of dynamic size that does not initialize.

\ingroup fcpptcontainer

\tparam T Must be a POD type.

\tparam A The allocator type.
*/
template <typename T, typename A>
class dynamic_array
{
  static_assert(std::is_pod_v<T>, "T must be a POD");

  FCPPT_NONMOVABLE(dynamic_array);

public:
  using pointer = typename A::pointer;

  using const_pointer = typename A::const_pointer;

  using size_type = typename A::size_type;

  explicit dynamic_array(size_type);

  dynamic_array(size_type, A);

  ~dynamic_array() noexcept;

  [[nodiscard]] pointer data() noexcept;

  [[nodiscard]] const_pointer data() const noexcept;

  [[nodiscard]] pointer data_end() noexcept;

  [[nodiscard]] const_pointer data_end() const noexcept;

  [[nodiscard]] size_type size() const noexcept;

private:
  A alloc_;

  pointer data_;

  size_type size_;
};

}
}

#endif
