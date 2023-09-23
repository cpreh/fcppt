//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/algorithm/map.hpp>
#include <fcppt/array/join.hpp>
#include <fcppt/array/size.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/make_pos_range.hpp>
#include <fcppt/container/grid/object_decl.hpp> // IWYU pragma: export
#include <fcppt/container/grid/offset.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/dim/contents.hpp>
#include <fcppt/math/dim/null.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename T, fcppt::container::grid::size_type N, typename A>
fcppt::container::grid::object<T, N, A>::object()
    : container_(), size_(fcppt::math::dim::null<dim>())
{
}

template <typename T, fcppt::container::grid::size_type N, typename A>
fcppt::container::grid::object<T, N, A>::object(dim const &_size, value_type const &_value)
    : container_(fcppt::math::dim::contents(_size), _value), size_(_size)
{
}

template <typename T, fcppt::container::grid::size_type N, typename A>
template <typename Function>
fcppt::container::grid::object<T, N, A>::object(dim const &_size, Function const &_function)
    : container_(fcppt::algorithm::map<container>(
          fcppt::container::grid::make_pos_range(_size), _function)),
      size_(_size)
{
}

template <typename T, fcppt::container::grid::size_type N, typename A>
template <typename Arg1, typename... Args, typename>
fcppt::container::grid::object<T, N, A>::object(Arg1 &&_arg1, Args &&..._args)
    : container_(fcppt::algorithm::map<container>(
          fcppt::array::join(std::forward<Arg1>(_arg1), std::forward<Args>(_args)...),
          [](auto &&_value) { return std::forward<decltype(_value)>(_value); })),
      size_(
          fcppt::array::size<std::remove_cvref_t<Arg1>>::value,
          sizeof...(Args) + 1U)
{
  static_assert(
      std::conjunction_v<std::is_same<
          fcppt::array::size<std::remove_cvref_t<Arg1>>,
          fcppt::array::size<std::remove_cvref_t<Args>>>...>,
      "All rows must have the size size");

  static_assert(
      std::conjunction_v<
          std::
              is_same<T, fcppt::type_traits::value_type<std::remove_cvref_t<Arg1>>>,
          std::is_same<
              T,
              fcppt::type_traits::value_type<std::remove_cvref_t<Args>>>...>,
      "All rows must have value_type T");
}

template <typename T, fcppt::container::grid::size_type N, typename A>
fcppt::container::grid::object<T, N, A>::object(object const &) = default;

template <typename T, fcppt::container::grid::size_type N, typename A>
fcppt::container::grid::object<T, N, A>::object(object &&_other) noexcept(
    std::is_nothrow_move_constructible_v<T>)
    : container_(std::move(_other.container_)), size_(std::move(_other.size_))
{
}

template <typename T, fcppt::container::grid::size_type N, typename A>
fcppt::container::grid::object<T, N, A> &
fcppt::container::grid::object<T, N, A>::operator=(object const &) = default;

template <typename T, fcppt::container::grid::size_type N, typename A>
fcppt::container::grid::object<T, N, A> &fcppt::container::grid::object<T, N, A>::operator=(
    object &&_other) noexcept(std::is_nothrow_move_assignable_v<T>)
{
  if (this == &_other)
  {
    return *this;
  }

  container_ = std::move(_other.container_);

  size_ = std::move(_other.size_);

  return *this;
}

namespace fcppt::container::grid
{
template <typename T, fcppt::container::grid::size_type N, typename A>
object<T, N, A>::~object() = default;
}

template <typename T, fcppt::container::grid::size_type N, typename A>
typename fcppt::container::grid::object<T, N, A>::reference
fcppt::container::grid::object<T, N, A>::get_unsafe(pos const &_pos)
{
  return container_[fcppt::container::grid::offset(_pos, size_)];
}

template <typename T, fcppt::container::grid::size_type N, typename A>
typename fcppt::container::grid::object<T, N, A>::const_reference
fcppt::container::grid::object<T, N, A>::get_unsafe(pos const &_pos) const
{
  return container_[fcppt::container::grid::offset(_pos, size_)];
}

template <typename T, fcppt::container::grid::size_type N, typename A>
typename fcppt::container::grid::object<T, N, A>::dim const &
fcppt::container::grid::object<T, N, A>::size() const
{
  return size_;
}

template <typename T, fcppt::container::grid::size_type N, typename A>
typename fcppt::container::grid::object<T, N, A>::size_type
fcppt::container::grid::object<T, N, A>::content() const
{
  return fcppt::math::dim::contents(size_);
}

template <typename T, fcppt::container::grid::size_type N, typename A>
bool fcppt::container::grid::object<T, N, A>::empty() const
{
  return this->content() == 0U;
}

template <typename T, fcppt::container::grid::size_type N, typename A>
typename fcppt::container::grid::object<T, N, A>::iterator
fcppt::container::grid::object<T, N, A>::begin()
{
  return container_.begin();
}

template <typename T, fcppt::container::grid::size_type N, typename A>
typename fcppt::container::grid::object<T, N, A>::iterator
fcppt::container::grid::object<T, N, A>::end()
{
  return container_.end();
}

template <typename T, fcppt::container::grid::size_type N, typename A>
typename fcppt::container::grid::object<T, N, A>::const_iterator
fcppt::container::grid::object<T, N, A>::begin() const
{
  return container_.begin();
}

template <typename T, fcppt::container::grid::size_type N, typename A>
typename fcppt::container::grid::object<T, N, A>::const_iterator
fcppt::container::grid::object<T, N, A>::end() const
{
  return container_.end();
}

template <typename T, fcppt::container::grid::size_type N, typename A>
void fcppt::container::grid::object<T, N, A>::swap(object &_other)
{
  container_.swap(_other.container_);

  std::swap(size_, _other.size_);
}

template <typename T, fcppt::container::grid::size_type N, typename A>
void fcppt::container::grid::swap(
    fcppt::container::grid::object<T, N, A> &_a, fcppt::container::grid::object<T, N, A> &_b)
{
  _a.swap(_b);
}

#endif
