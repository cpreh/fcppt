//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/difference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/math/matrix/object_fwd.hpp>
#include <fcppt/math/matrix/row_type_fwd.hpp>
#include <fcppt/math/matrix/detail/row_view_fwd.hpp>
#include <fcppt/math/vector/object_decl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::matrix
{
/**
\brief A class representing a static matrix

Represents a static <code>R</code> by <code>C</code> matrix, which is a matrix
consisting of <code>R</code> rows and <code>C</code> columns.

\ingroup fcpptmathmatrix

\tparam T The matrix's <code>value_type</code>

\tparam R The number of rows

\tparam C The number of columns

\tparam S The matrix's storage type

See \ref fcpptmathmatrix for more information.
*/
template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
class object
{
public:
  using static_rows = fcppt::math::static_size<R>;

  using static_columns = fcppt::math::static_size<C>;

  using static_size = static_rows;

  using dim_wrapper = fcppt::math::static_size<static_rows::value * static_columns::value>;

  /**
  \brief A typedef for the \p S parameter
  */
  using storage_type = S;

  /**
  \brief A type that counts the number of elements in a matrix.
  */
  using size_type = fcppt::math::size_type;

  /**
  \brief A type that provides the difference between the addresses of two elements in a matrix.
  */
  using difference_type = fcppt::math::difference_type;

  /**
  \brief A type that represents the data type stored in a matrix.
  */
  using value_type = T;

  /**
  \brief A reference to a row of the matrix.
  */
  using reference =
      fcppt::math::vector::object<T, C, fcppt::math::matrix::detail::row_view<T, C, S>>;

  /**
  \brief A reference to an element of the matrix.
  */
  using inner_reference = typename reference::reference;

  /**
  \brief A const reference to a row of the matrix.
  */
  using const_reference =
      fcppt::math::vector::object<T, C, fcppt::math::matrix::detail::row_view<T, C, S const>>;

  /**
  \brief A const reference to an element of the matrix.
  */
  using const_inner_reference = typename const_reference::const_reference;

  /**
  \brief The type of a row, which is a vector of <code>C</code> elements.
  */
  using row_type = fcppt::math::matrix::row_type<T, C>;

  /**
  \brief Construct an uninitialized matrix

  \warning
  The content of the matrix will be undefined (not null) after
  initialization
  */
  explicit object(fcppt::no_init const &);

  /**
  \brief Construct a matrix from a storage source
  */
  explicit object(storage_type &&);

  /**
  \brief Constructs a matrix from <code>R</code> rows

  Constructs a matrix by using <code>R</code> arguments of type
  #fcppt::math::matrix::object::row_type. You can use #fcppt::math::matrix::row to create them.
  */
  template <
      typename... Args,
      typename = std::enable_if_t<std::conjunction_v<
          std::bool_constant<sizeof...(Args) == R>,
          std::is_same<row_type, fcppt::type_traits::remove_cv_ref_t<Args>>...>>>
  explicit object(Args &&...);

  /**
  \brief Create a matrix from a matrix with the same dimension and value
  type but different storage type

  \tparam OtherStorage The other matrix's storage type
  */
  template <typename OtherStorage>
  explicit object(fcppt::math::matrix::object<T, R, C, OtherStorage> const &);

  /**
  \brief Copy the values from a different matrix of the same size but
  different storage type

  \tparam OtherStorage The other matrix's storage type
  */
  template <typename OtherStorage>
  object &operator=(fcppt::math::matrix::object<T, R, C, OtherStorage> const &);

  template <typename S2>
  object &operator+=(object<T, R, C, S2> const &);

  template <typename S2>
  object &operator-=(object<T, R, C, S2> const &);

  /**
  \brief Multiply a matrix by a scalar
  */
  object &operator*=(value_type const &);

  /**
  \brief Returns a reference to a row in the matrix

  \warning
  Behaviour is undefined if the index is out of range.
  */
  [[nodiscard]] reference get_unsafe(size_type);

  /**
  \brief Returns a reference to a (constant) row in the matrix

  \warning
  Behaviour is undefined if the index is out of range.
  */
  [[nodiscard]] const_reference get_unsafe(size_type) const;

  /**
  \brief Returns the number of rows in the matrix.
  */
  [[nodiscard]] constexpr static size_type rows();

  /**
  \brief Returns the number of columns in the matrix.
  */
  [[nodiscard]] constexpr static size_type columns();

  [[nodiscard]] S &storage();

  [[nodiscard]] S const &storage() const;

  [[nodiscard]] inner_reference m00();

  [[nodiscard]] const_inner_reference m00() const;

  [[nodiscard]] inner_reference m01();

  [[nodiscard]] const_inner_reference m01() const;

  [[nodiscard]] inner_reference m02();

  [[nodiscard]] const_inner_reference m02() const;

  [[nodiscard]] inner_reference m03();

  [[nodiscard]] const_inner_reference m03() const;

  [[nodiscard]] inner_reference m10();

  [[nodiscard]] const_inner_reference m10() const;

  [[nodiscard]] inner_reference m11();

  [[nodiscard]] const_inner_reference m11() const;

  [[nodiscard]] inner_reference m12();

  [[nodiscard]] const_inner_reference m12() const;

  [[nodiscard]] inner_reference m13();

  [[nodiscard]] const_inner_reference m13() const;

  [[nodiscard]] inner_reference m20();

  [[nodiscard]] const_inner_reference m20() const;

  [[nodiscard]] inner_reference m21();

  [[nodiscard]] const_inner_reference m21() const;

  [[nodiscard]] inner_reference m22();

  [[nodiscard]] const_inner_reference m22() const;

  [[nodiscard]] inner_reference m23();

  [[nodiscard]] const_inner_reference m23() const;

  [[nodiscard]] inner_reference m30();

  [[nodiscard]] const_inner_reference m30() const;

  [[nodiscard]] inner_reference m31();

  [[nodiscard]] const_inner_reference m31() const;

  [[nodiscard]] inner_reference m32();

  [[nodiscard]] const_inner_reference m32() const;

  [[nodiscard]] inner_reference m33();

  [[nodiscard]] const_inner_reference m33() const;

private:
  S storage_;
};

}

#endif
