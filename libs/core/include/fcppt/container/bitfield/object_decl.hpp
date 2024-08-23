//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_BITFIELD_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/array/size.hpp>
#include <fcppt/container/bitfield/array.hpp>
#include <fcppt/container/bitfield/default_internal_type.hpp>
#include <fcppt/container/bitfield/object_fwd.hpp> // IWYU pragma: keep
#include <fcppt/container/bitfield/proxy_fwd.hpp>
#include <fcppt/container/bitfield/value_type.hpp>
#include <fcppt/container/bitfield/detail/make_internal_type.hpp>
#include <fcppt/enum/is_object.hpp>
#include <fcppt/enum/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::bitfield
{
/**
\brief A statically sized bitfield.

\ingroup fcpptcontainerbitfield

\tparam ElementType An enumeration type.

\tparam InternalType The internal storage type. Must be unsigned. This is
#fcppt::container::bitfield::default_internal_type by default.

See \ref fcpptcontainerbitfield for more information.
*/
template <typename ElementType, typename InternalType>
class object
{
public:
  static_assert(fcppt::enum_::is_object<ElementType>::value, "ElementType must be an enum");

  using element_type = ElementType;

  /**
  \brief The value type of the underlying array.
  */
  using internal_type = std::conditional_t<
      std::is_same_v<fcppt::container::bitfield::default_internal_type, InternalType>,
      fcppt::container::bitfield::detail::make_internal_type<ElementType>,
      InternalType>;

  static_assert(std::is_unsigned_v<internal_type>, "internal_type must be unsigned");

  /**
  \brief The number of array elements.
  */
  using static_size = fcppt::enum_::size<element_type>;

  /**
  \brief The internal array type.
  */
  using array_type = fcppt::container::bitfield::array<static_size, internal_type>;

  /**
  \brief The size of the underlying array.
  */
  using array_size = fcppt::array::size<array_type>;

  /**
  \brief The size type which is taken from <code>static_size</code>.
  */
  using size_type = typename static_size::value_type;

  /**
  \brief The value type, which is bool.
  */
  using value_type = fcppt::container::bitfield::value_type;

  /**
  \brief A type denoting a reference to a mask value (a reference to a
  boolean, basically).

  Note that this is <em>not</em> a <code>bool</code> nor an
  <code>internal_type</code>, but a proxy class.
  */
  using reference = fcppt::container::bitfield::proxy<array_type>;

  /**
  \brief A type denoting a const reference to a mask value (a reference to a
  boolean, basically).

  Note that this is <em>not</em> a <code>bool</code> nor an
  <code>internal_type</code>, but a proxy class.
  */
  using const_reference = fcppt::container::bitfield::proxy<array_type const>;

  /**
  \brief Initializer list type used to initialize a bitfield.
  */
  using initializer_list_type = std::initializer_list<ElementType>;

  /**
  \brief Constructs an uninitialized bitfield.
  */
  explicit object(fcppt::no_init const &);

  /**
  \brief Constructs a bitfield using an initializer list, setting every
  bit from the list to true.
  */
  object(initializer_list_type const &);

  /**
  \brief Constructs a bitfield from its internal array type.
  */
  explicit object(array_type const &);

  /**
  \brief Returns a const reference to the specified bit.
  */
  [[nodiscard]] const_reference operator[](ElementType) const;

  /**
  \brief Returns a reference to the specified bit.
  */
  [[nodiscard]] reference operator[](ElementType);

  /**
  \brief Sets the specified bit to true/false.
  */
  void set(ElementType where, value_type value);

  /**
  \brief Returns if the specified bit is set.
  */
  [[nodiscard]] value_type get(ElementType) const;

  /**
  \brief Accessor to the internal array.
  */
  [[nodiscard]] array_type &array();

  /**
  \brief Const accessor to the internal array.
  */
  [[nodiscard]] array_type const &array() const;

  /**
  \brief Returns the bitfield with all bits set to zero.
  */
  [[nodiscard]] static object null();

private:
  static size_type to_index(ElementType);

  array_type array_;
};

}

#endif
