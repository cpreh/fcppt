//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_RAW_VECTOR_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/not.hpp>
#include <fcppt/container/raw_vector/object_fwd.hpp>
#include <fcppt/container/raw_vector/rep_fwd.hpp>
#include <fcppt/type_traits/is_iterator_of_category.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace raw_vector
{
/**
\brief A special vector class that can handle uninitialized memory.

\ingroup fcpptcontainerraw_vector

\tparam T A POD type.

\tparam A The allocator type.

See \ref fcpptcontainerraw_vector for more information.
*/
template <typename T, typename A>
class object
{
  static_assert(std::is_pod_v<T>, "T must be a POD type");

  FCPPT_NONCOPYABLE(object);

public:
  using value_type = T;

  using allocator_type = A;

  using size_type = typename A::size_type;

  using difference_type = typename A::difference_type;

  using pointer = typename A::pointer;

  using const_pointer = typename A::const_pointer;

  using reference = typename A::reference;

  using const_reference = typename A::const_reference;

  using iterator = pointer;

  using const_iterator = const_pointer;

  [[nodiscard]] iterator begin() noexcept;

  [[nodiscard]] const_iterator begin() const noexcept;

  [[nodiscard]] iterator end() noexcept;

  [[nodiscard]] const_iterator end() const noexcept;

  [[nodiscard]] reference operator[](size_type) noexcept;

  [[nodiscard]] const_reference operator[](size_type) const noexcept;

  [[nodiscard]] reference front() noexcept;

  [[nodiscard]] const_reference front() const noexcept;

  [[nodiscard]] reference back() noexcept;

  [[nodiscard]] const_reference back() const noexcept;

  /**
  \brief Returns the pointer to the store.
  */
  [[nodiscard]] pointer data() noexcept;

  /**
  \brief Returns the pointer to the store.
  */
  [[nodiscard]] const_pointer data() const noexcept;

  /**
  \brief Returns the pointer to the end of the store.

  Equal to <code>data() + size()</code>.
  */
  [[nodiscard]] pointer data_end() noexcept;

  /**
  \brief Returns the pointer to the end of the store.

  Equal to <code>data() + size()</code>.
  */
  [[nodiscard]] const_pointer data_end() const noexcept;

  object();

  explicit object(A const &);

  object(size_type sz, T const &value);

  object(size_type sz, T const &value, A const &);

  template <typename In>
  object(In beg, In end);

  template <typename In>
  object(In beg, In end, A const &);

  /**
  \brief Reuse the storage of another container.
  */
  explicit object(fcppt::container::raw_vector::rep<A> const &) noexcept;

  object(std::initializer_list<value_type>);

  object(std::initializer_list<value_type>, A const &);

  object(object &&) noexcept;

  ~object() noexcept;

  object &operator=(object &&) noexcept;

  void push_back(T const &);

  void pop_back() noexcept;

  void clear() noexcept;

  [[nodiscard]] size_type size() const noexcept;

  [[nodiscard]] bool empty() const noexcept;

  [[nodiscard]] size_type capacity() const noexcept;

  void swap(object &) noexcept;

  void resize(size_type sz, T const &value);

  void reserve(size_type sz);

  [[nodiscard]] allocator_type get_allocator() const;

  iterator insert(iterator position, T const &t);

  void insert(iterator position, size_type sz, T const &value);

  template <typename In>
  void insert(iterator position, In beg, In end);

  iterator erase(iterator position) noexcept;

  iterator erase(iterator first, iterator last) noexcept;

  void shrink_to_fit();

private:
  template <typename In>
  std::enable_if_t<
      fcppt::not_(
          fcppt::type_traits::is_iterator_of_category<In, std::forward_iterator_tag>::value),
      void>
  insert_impl(iterator position, In begin, In end);

  template <typename In>
  std::enable_if_t<
      fcppt::type_traits::is_iterator_of_category<In, std::forward_iterator_tag>::value,
      void>
  insert_impl(iterator position, In begin, In end);

  [[nodiscard]] size_type new_capacity(size_type new_size) const noexcept;

  void reallocate(size_type new_cap);

  void set_pointers(pointer src, size_type sz, size_type cap) noexcept;

  void deallocate() noexcept;

  class impl
  {
    FCPPT_NONCOPYABLE(impl);

  public:
    explicit impl(A const &) noexcept;

    explicit impl(fcppt::container::raw_vector::rep<A> const &) noexcept;

    impl(impl &&) noexcept;

    impl &operator=(impl &&) noexcept;

    ~impl() noexcept;

    void reset_pointers() noexcept;

    A alloc_; // NOLINT(misc-non-private-member-variables-in-classes)

    pointer first_, // NOLINT(misc-non-private-member-variables-in-classes)
        last_, // NOLINT(misc-non-private-member-variables-in-classes)
        cap_; // NOLINT(misc-non-private-member-variables-in-classes)
  };

  explicit object(impl &&);

  impl impl_;
};

/**
\ingroup fcpptcontainerraw_vector
*/
template <typename T, typename A>
void swap(
    fcppt::container::raw_vector::object<T, A> &,
    fcppt::container::raw_vector::object<T, A> &) noexcept;

}
}
}

#endif
