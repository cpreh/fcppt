//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/object.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

int main()
{
  //! [main]
  using string_tree = fcppt::container::tree::object<std::string>;

  string_tree tree{"hello"};

  // Immediately change the value
  tree.value(tree.value() + " world");

  // The tree is empty since it has no children
  std::cout << "Is the tree empty? " << tree.empty() << '\n';

  {
    // Adding two items by moving
    string_tree child1{"blubb"};

    tree.push_back(std::move(child1));

    string_tree child2{"blah"};

    tree.push_back(std::move(child2));
  }

  // adding "by value"
  tree.push_back("foobar");

  // Now the tree isn't empty anymore
  std::cout << "Is the tree empty? " << tree.empty() << '\n';

  // Outputs 3
  std::cout << "How many children does the tree have: " << tree.size() << '\n';

  // Outputs: hello world
  std::cout << "The tree value is: " << tree.value() << '\n';

  // Output the first level of the tree below the root.
  // Note that iterator::value_type is string_tree.
  for (string_tree const &item : tree)
  {
    std::cout << item.value() << '\n';
  }

  fcppt::optional::maybe_void(
      tree.front(),
      [](fcppt::reference<string_tree> const _first_child) {
        std::cout << "First child has a parent: " << _first_child.get().parent().has_value()
                  << '\n';
      });
  //! [main]
}
