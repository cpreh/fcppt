//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/nonmovable.hpp>
#include <fcppt/not.hpp>
#include <fcppt/concepts/move_constructible.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>

class test
{
  FCPPT_NONMOVABLE(test);
public:
  test() = default;
  ~test() = default;
};

int main()
{
  static_assert(fcppt::concepts::move_constructible<int>);
  static_assert(fcppt::concepts::move_constructible<std::unique_ptr<int>>);
  static_assert(fcppt::not_(fcppt::concepts::move_constructible<test>));
}
