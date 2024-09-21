//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_BOX_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_MATH_BOX_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/math/box/object_fwd.hpp> // IWYU pragma: keep
#include <fcppt/math/dim/static_fwd.hpp>
#include <fcppt/math/vector/static.hpp>

namespace fcppt::math::box
{
/**
\brief A class representing axis aligned boxes, cubes, hypercubes, ...

\tparam T The box's <code>value_type</code>

\tparam N The box's (numeric) dimension

\ingroup fcpptmathbox
*/
template <typename T, fcppt::math::size_type N>
class object
{
public:
  /**
  \brief A type that represents the data type stored in a box's vector/dimension.
  */
  using value_type = T;

  using dim_wrapper = fcppt::math::static_size<N>;

  /**
  \brief A type that represents the data type stored in a box's
  vector/dimension (synonymous to value_type).
  */
  using scalar = value_type;

  /**
  \brief A type that counts the number of elements in a box's
  vector/dimension.
  */
  using size_type = fcppt::math::size_type;

  /**
  \brief A type represents a box's position.
  */
  using vector = fcppt::math::vector::static_<T, N>;

  /**
  \brief A type represents a box's size.
  */
  using dim = fcppt::math::dim::static_<T, N>;

  /**
  \brief Construct an uninitialized box

  \warning
  The content of the box will be undefined (not null) after
  initialization
  */
  explicit object(fcppt::no_init const &);

  /**
  \brief Construct a box from position and size
  */
  object(vector const &pos, dim const &size);

  FCPPT_DECLARE_STRONG_TYPEDEF(vector, min_t);
  FCPPT_DECLARE_STRONG_TYPEDEF(vector, max_t);

  /**
  \brief Construct a box from two positions
  */
  object(min_t &&, max_t &&); // NOLINT(cppcoreguidelines-rvalue-reference-param-not-moved)

  /**
  \brief Return the box's position
  */
  [[nodiscard]] vector &pos();

  [[nodiscard]] vector const &pos() const;

  [[nodiscard]] vector &min();

  [[nodiscard]] vector const &min() const;

  [[nodiscard]] vector &max();

  [[nodiscard]] vector const &max() const;

  [[nodiscard]] dim size() const;

  [[nodiscard]] value_type left() const;

  [[nodiscard]] value_type right() const;

  [[nodiscard]] value_type top() const;

  [[nodiscard]] value_type bottom() const;

  [[nodiscard]] value_type front() const;

  [[nodiscard]] value_type back() const;

private:
  vector min_;

  vector max_;
};

}

#endif
