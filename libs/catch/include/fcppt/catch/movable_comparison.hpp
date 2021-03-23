//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CATCH_MOVABLE_COMPARISON_HPP_INCLUDED
#define FCPPT_CATCH_MOVABLE_COMPARISON_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/catch/movable_impl.hpp>

namespace fcppt
{
namespace catch_
{
template <typename Type>
bool operator==(
    fcppt::catch_::movable<Type> const &_left, fcppt::catch_::movable<Type> const &_right)
{
  return _left.value() == _right.value();
}

}
}

#endif
