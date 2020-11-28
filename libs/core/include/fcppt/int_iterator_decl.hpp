//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_INT_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_INT_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/int_iterator_fwd.hpp>
#include <fcppt/iterator/base_decl.hpp>
#include <fcppt/iterator/types_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief An iterator over integers.

\ingroup fcpptvarious
*/
template <typename Int>
class int_iterator final
    : public fcppt::iterator::base<
          fcppt::iterator::types<fcppt::int_iterator<Int>, Int, Int, Int, std::input_iterator_tag>>
{
public:
  explicit int_iterator(Int) noexcept;

  void increment() noexcept;

  [[nodiscard]] bool equal(int_iterator) const noexcept;

  [[nodiscard]] Int dereference() const noexcept;

private:
  Int value_;
};

}

#endif
