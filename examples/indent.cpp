//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_recursive.hpp>
#include <fcppt/recursive.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/indent/extra.hpp>
#include <fcppt/indent/level.hpp>
#include <fcppt/indent/print.hpp>
#include <fcppt/indent/start.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <exception>
#include <ostream>
#include <iostream>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace
{
// [indent_tree]
struct tree
{
  using container = std::vector<fcppt::recursive<tree>>;
  int value;
  container children;
};
// [indent_tree]

// [indent_output]
void output(std::ostream &_stream, tree const &_tree, fcppt::indent::level const _indent)
{
  _stream << fcppt::indent::print(_indent) << _tree.value << '\n';
  for (fcppt::recursive<tree> const &inner : _tree.children)
  {
    output(_stream, inner.get(), fcppt::indent::extra(_indent));
  }
}
// [indent_output]
}

int main()
try
{
// [indent_example]
  tree const value{
      .value = 1,
      .children = fcppt::container::make<tree::container>(
          fcppt::make_recursive(tree{.value = 2, .children = tree::container{}}),
          fcppt::make_recursive(tree{.value = 3, .children = tree::container{}}))};

  output(std::cout, value, fcppt::indent::start());
// [indent_example]

  return EXIT_SUCCESS;
}
catch(std::exception const &_error)
{
  std::cerr << _error.what() << '\n';
  return EXIT_FAILURE;
}
