//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DIM_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_MATH_DIM_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/difference_type.hpp>
#include <fcppt/math/is_static_storage.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/math/dim/object_fwd.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::dim
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)
FCPPT_PP_DISABLE_VC_WARNING(5027)

/**
\brief A class representing a static n-dimensional dimension
\tparam T The dim's <code>value_type</code>
\tparam N The dim's dimension type (this is not necessarily a number!)
\tparam S The dim's storage type
\ingroup fcpptmathdim

See \ref fcpptmathdim for more information.
*/
template <typename T, fcppt::math::size_type N, typename S>
class object
{
public:
  /**
  \brief A typedef for the \p N parameter
  */
  using dim_wrapper = fcppt::math::static_size<N>;

  using static_size = dim_wrapper;

  /**
  \brief A typedef for the \p S parameter
  */
  using storage_type = S;

  /**
  \brief A type that counts the number of elements in a dim.
  */
  using size_type = fcppt::math::size_type;

  /**
  \brief A type that provides the difference between the addresses of two elements in a dim.
  */
  using difference_type = fcppt::math::difference_type;

  /**
  \brief A type that represents the data type stored in a dim.
  */
  using value_type = T;

  /**
  \brief A type that provides a reference to an element stored in a dim.
  */
  using reference = typename storage_type::reference;

  /**
  \brief A type that provides a reference to a <code>const</code> element stored in a dim for
  reading and performing <code>const</code> operations.
  */
  using const_reference = typename storage_type::const_reference;

  /**
  \brief Construct an uninitialized dim

  \warning
  The content of the dim will be undefined (not null) after
  initialization
  */
  explicit object(fcppt::no_init const &);

  /**
  \brief Construct a dim from a storage source
  */
  explicit object(storage_type &&);

  template <
      typename... Args,
      typename = std::enable_if_t<std::conjunction_v<
          fcppt::math::is_static_storage<S>,
          std::bool_constant<sizeof...(Args) == N>,
          std::is_constructible<T, Args>...>>>
  constexpr explicit object(Args &&...) noexcept(
      std::conjunction_v<std::is_nothrow_constructible<T, Args>...>);

  /**
  \brief Create a dim from a dim with the same dimension and value type but different storage type
  \tparam OtherStorage The other dim's storage type
  */
  template <typename OtherStorage>
  explicit object(fcppt::math::dim::object<T, N, OtherStorage> const &);

  /**
  \brief Copy the values from a different dim
  \tparam OtherStorage The other dim's storage type
  */
  template <typename OtherStorage>
  object &operator=(fcppt::math::dim::object<T, N, OtherStorage> const &);

  /**
  \brief Add a dim.
  */
  template <typename S2>
  object &operator+=(object<T, N, S2> const &);

  /**
  \brief Subtract a dim.
  */
  template <typename S2>
  object &operator-=(object<T, N, S2> const &);

  /**
  \brief Multiply by a dim.
  */
  template <typename S2>
  object &operator*=(object<T, N, S2> const &);

  /**
  \brief Multiply a dim by a scalar
  */
  object &operator*=(value_type const &);

  /**
  \brief Returns a reference to the dim element at a specified position.

  \warning
  Behaviour is undefined if the index is out of range.
  */
  [[nodiscard]] reference get_unsafe(size_type);

  /**
  \brief Returns a reference to the dim element at a specified position.

  \warning
  Behaviour is undefined if the index is out of range.
  */
  [[nodiscard]] const_reference get_unsafe(size_type) const;

  /**
  \brief Returns a reference to the first element in the dim
  */
  [[nodiscard]] reference w();

  /**
  \brief Returns a reference to the first element in the dim
  */
  [[nodiscard]] const_reference w() const;

  /**
  \brief Returns a reference to the second element in the dim
  */
  [[nodiscard]] reference h();

  /**
  \brief Returns a reference to the second element in the dim
  */
  [[nodiscard]] const_reference h() const;

  /**
  \brief Returns a reference to the third element in the dim
  */
  [[nodiscard]] reference d();

  /**
  \brief Returns a reference to the third element in the dim
  */
  [[nodiscard]] const_reference d() const;

  [[nodiscard]] S &storage();

  [[nodiscard]] S const &storage() const;

private:
  S storage_;
};

FCPPT_PP_POP_WARNING
}

#endif
