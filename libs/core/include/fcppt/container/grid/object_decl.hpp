//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/container/grid/dim_fwd.hpp>
#include <fcppt/container/grid/is_static_row.hpp>
#include <fcppt/container/grid/object_fwd.hpp> // IWYU pragma: keep
#include <fcppt/container/grid/pos_fwd.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/dim/object_decl.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::grid
{
/**
\brief An n-dimensional array.

\ingroup fcpptcontainergrid

See \ref fcpptcontainergrid for more information.
*/
template <typename T, fcppt::container::grid::size_type N, typename A>
class object
{
  // \cond
  static_assert(N >= 1U, "The dimensions of a grid cannot be zero");

  using container = std::vector<T, A>;
  // \endcond
public:
  using static_size = std::integral_constant<fcppt::container::grid::size_type, N>;

  using allocator_type = A;

  using value_type = T;

  using size_type = typename container::size_type;

  using difference_type = typename container::difference_type;

  using reference = typename container::reference;

  using const_reference = typename container::const_reference;

  using iterator = typename container::iterator;

  using const_iterator = typename container::const_iterator;

  /**
  \brief A type representing the dimension of the grid
  */
  using dim = fcppt::container::grid::dim<size_type, N>;

  /**
  \brief A type representing a position in the grid
  */
  using pos = fcppt::container::grid::pos<size_type, N>;

  /**
  \brief A signed version of pos
  */
  using signed_pos = fcppt::container::grid::pos<difference_type, N>;

  /**
  \brief An empty grid.
  */
  object();

  /**
  \brief Initialize the grid to a size and fill every cell with the same value
  \param d The size of the grid
  \param r The value to assign to each element of the grid
  */
  object(dim const &d, value_type const &r);

  /**
  \brief Initialize the grid by calling a function for every element

  Calls \a function for every position in the grid.

  \tparam Function A function of type <code>value_type (pos)</code>
  */
  template <typename Function>
  object(dim const &size, Function const &function);

  /**
  \brief Initialize the grid from a sequence of #fcppt::container::grid::static_row_type.

  Use #fcppt::container::grid::static_row to create a grid row.
  For example, calling this constructro with <code>static_row(1,2,3),static_row(4,5,6)</code>
  will yields a grid of size <code>3x2</code>.

  All arguments must have the same size (i.e. row length) and all rows must have value type
  <code>T</code>.
  */
  template <
      typename Arg1,
      typename... Args,
      typename = std::enable_if_t<std::conjunction_v<
          fcppt::container::grid::is_static_row<Arg1>,
          fcppt::container::grid::is_static_row<Args>...>>>
  explicit object(Arg1 &&, Args &&...);

  object(object const &);

  // TODO(philipp)
  // NOLINTNEXTLINE(cppcoreguidelines-noexcept-move-operations,hicpp-noexcept-move,performance-noexcept-move-constructor)
  object(object &&) noexcept(std::is_nothrow_move_constructible_v<T>);

  object &operator=(object const &);

  // NOLINTNEXTLINE(cppcoreguidelines-noexcept-move-operations,hicpp-noexcept-move,performance-noexcept-move-constructor)
  object &operator=(object &&) noexcept(std::is_nothrow_move_assignable_v<T>);

  ~object();

  /**
  \brief Returns a reference to the grid element at a specified position.

  \warning Behaviour is undefined if the position is out of range.
  */
  [[nodiscard]] reference get_unsafe(pos const &);

  /**
  \brief Returns a reference to the grid element at a specified position.

  \warning Behaviour is undefined if the position is out of range.
  */
  [[nodiscard]] const_reference get_unsafe(pos const &) const;

  /**
  \brief Returns the grid's size
  \note
  In contrast to the standard containers, this does not return a
  <code>size_type</code> value, but the dimension. Use content() to get
  the number of elements
  */
  [[nodiscard]] dim const &size() const;

  /**
  \brief Returns the number of elements in the grid.
  */
  [[nodiscard]] size_type content() const;

  /**
  \brief Tests if the grid is empty.
  */
  [[nodiscard]] bool empty() const;

  [[nodiscard]] iterator begin();

  [[nodiscard]] iterator end();

  [[nodiscard]] const_iterator begin() const;

  [[nodiscard]] const_iterator end() const;

  /**
  \brief Exchanges the elements of two grids.
  */
  void swap(object &) noexcept;

private:
  container container_;

  dim size_;
};

template <typename T, fcppt::container::grid::size_type N, typename A>
void swap(fcppt::container::grid::object<T, N, A> &, fcppt::container::grid::object<T, N, A> &) noexcept;

}

#endif
