//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// ![homogenous_pair]
#include <fcppt/homogenous_pair.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>

int main()
{
  using int_pair = fcppt::homogenous_pair<int>;

  int_pair test1(1, 2);

  test1.first = 3;

  fcppt::io::cout() << test1 << FCPPT_TEXT('\n');
}
// ![homogenous_pair]
