//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_INT_RANGE_DECL_HPP_INCLUDED
#define FCPPT_INT_RANGE_DECL_HPP_INCLUDED

#include <fcppt/int_iterator_fwd.hpp>
#include <fcppt/type_iso/undecorated_type.hpp>

namespace fcppt
{
/**
\brief A forward range over integers

\ingroup fcpptvarious
*/
template <typename Int>
class int_range
{
public:
  using value_type = Int;

  using iterator = fcppt::int_iterator<Int>;

  using const_iterator = iterator;

  using size_type = fcppt::type_iso::undecorated_type<Int>;

  /**
  \brief Creates a range

  If end < begin the range will be empty.

  \param begin The first element in the range

  \param end The element one past the end
  */
  constexpr int_range(Int begin, Int end);

  [[nodiscard]] constexpr iterator begin() const;

  [[nodiscard]] constexpr iterator end() const;

  [[nodiscard]] constexpr size_type size() const;

private:
  Int begin_;

  Int end_;
};

}

#endif
