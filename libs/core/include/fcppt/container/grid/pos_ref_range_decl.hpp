//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_POS_REF_RANGE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REF_RANGE_DECL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/container/grid/object_decl.hpp> // IWYU pragma: keep
#include <fcppt/container/grid/pos_range_impl.hpp>
#include <fcppt/container/grid/pos_ref_iterator_fwd.hpp>
#include <fcppt/container/grid/pos_ref_range_fwd.hpp> // IWYU pragma: keep
#include <fcppt/container/grid/pos_type.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::grid
{
/**
\brief A range over grid references

\ingroup fcpptcontainergrid
*/
template <typename Grid>
class pos_ref_range
{
public:
  using iterator = fcppt::container::grid::pos_ref_iterator<Grid>;

  using const_iterator = iterator;

  using pos_range = fcppt::container::grid::pos_range<
      fcppt::type_traits::value_type<fcppt::container::grid::pos_type<std::remove_cv_t<Grid>>>,
      Grid::static_size::value>;

  using min_type = typename pos_range::min_type;

  using sup_type = typename pos_range::sup_type;

  using size_type = typename pos_range::size_type;

  pos_ref_range(Grid &, min_type, sup_type);

  [[nodiscard]] iterator begin() const;

  [[nodiscard]] iterator end() const;

  [[nodiscard]] size_type size() const;

  [[nodiscard]] min_type const &min() const;

  [[nodiscard]] sup_type const &sup() const;

private:
  using pos_iterator = typename pos_range::iterator;

  [[nodiscard]] iterator make_iterator(pos_iterator) const;

  fcppt::reference<Grid> grid_;

  pos_range pos_range_;
};

}

#endif
