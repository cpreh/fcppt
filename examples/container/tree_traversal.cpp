//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/container/tree/object.hpp>
#include <fcppt/container/tree/pre_order.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <fcppt/config/external_end.hpp>

int main()
try
{
  //! [main]
  using string_tree = fcppt::container::tree::object<std::string>;

  // Create a tree, insert 5 elements below the root
  string_tree tree{"hello"};

  tree.push_back("foo");

  tree.push_back("bar");

  tree.push_back("baz");

  tree.front().get_unsafe().get().push_back("qux");

  // Create a traversal and "attach" it to the tree in the ctor
  // Then use it like a forward-iterable container!
  // This outputs:
  //
  // hello, foo, qux, bar, baz
  for (string_tree const &item : fcppt::container::tree::pre_order<string_tree const>(tree))
  {
    std::cout << item.value() << std::endl;
  }
  //! [main]
}
catch(std::exception const &error)
{
  std::cerr << error.what() << '\n';
}
