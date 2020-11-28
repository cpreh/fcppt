//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_BUFFER_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_BUFFER_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/container/buffer/object_fwd.hpp>
#include <fcppt/container/raw_vector/rep_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace buffer
{
/**
\brief A contiguous container for uninitialized data that contains a write and a read area.

\ingroup fcpptcontainerbuffer

\tparam T Must be a POD type.

\tparam A The allocator type.

See \ref fcpptcontainerbuffer for more information.
*/
template <typename T, typename A>
class object
{
  static_assert(std::is_pod<T>::value, "T must be a POD");

  FCPPT_NONCOPYABLE(object);

public:
  using value_type = T;

  using allocator_type = A;

  using size_type = typename A::size_type;

  using pointer = typename A::pointer;

  using const_pointer = typename A::const_pointer;

  using const_reference = typename A::const_reference;

  using const_iterator = typename A::const_pointer;

  /**
  \brief Constructs an uninitialized buffer.

  Constructs a buffer with a write area of size \a sz.
  */
  explicit object(size_type write_sz);

  /**
  \brief Constructs an uninitialized buffer with custom allocator.

  Constructs a buffer with a write area of size \a sz.
  */
  object(size_type write_sz, A);

  object(object &&) noexcept;

  object &operator=(object &&) noexcept;

  ~object() noexcept;

  /**
  \brief The beginning of the read area.
  */
  [[nodiscard]] const_iterator begin() const noexcept;

  /**
  \brief The end of the read area.
  */
  [[nodiscard]] const_iterator end() const noexcept;

  /**
  \brief The read area at a given position.
  */
  [[nodiscard]] const_reference operator[](size_type) const noexcept;

  /**
  \brief The beginning of the read area.
  */
  [[nodiscard]] const_pointer read_data() const noexcept;

  /**
  \brief The end of the read area.
  */
  [[nodiscard]] const_pointer read_data_end() const noexcept;

  /**
  \brief The beginning of the write area.
  */
  [[nodiscard]] pointer write_data() noexcept;

  /**
  \brief The end of the write area.
  */
  [[nodiscard]] pointer write_data_end() noexcept;

  /**
  \brief The size of the read area.
  */
  [[nodiscard]] size_type read_size() const noexcept;

  /**
  \brief The size of the write area.
  */
  [[nodiscard]] size_type write_size() const noexcept;

  /**
  \brief Adds to the read area.

  Adds \a sz elements to the read area. This function should be
  called after data has been read into the write area.
  */
  void written(size_type sz) noexcept;

  /**
  \brief Resizes the write area.

  Sets the size of the write area to \a sz.
  */
  void resize_write_area(size_type sz);

  [[nodiscard]] allocator_type get_allocator() const;

  void swap(object &) noexcept;

  /**
  \brief Releases the storage.

  \see fcppt::container::buffer::to_raw_vector
  */
  [[nodiscard]] fcppt::container::raw_vector::rep<A> release() noexcept;

private:
  void release_internal() noexcept;

  struct impl
  {
    FCPPT_NONCOPYABLE(impl);

  public:
    impl(A const &, pointer first, size_type size);

    impl(impl &&) noexcept;

    impl &operator=(impl &&) noexcept;

    ~impl() noexcept;

    void deallocate() noexcept;

    A alloc_; // NOLINT(misc-non-private-member-variables-in-classes)

    pointer first_, // NOLINT(misc-non-private-member-variables-in-classes)
        read_end_, // NOLINT(misc-non-private-member-variables-in-classes)
        write_end_, // NOLINT(misc-non-private-member-variables-in-classes)
        cap_; // NOLINT(misc-non-private-member-variables-in-classes)
  };

  impl impl_;
};

template <typename T, typename A>
void swap(
    fcppt::container::buffer::object<T, A> &, fcppt::container::buffer::object<T, A> &) noexcept;

}
}
}

#endif
