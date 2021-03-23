//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("container::tree output", "[container],[tree]")
{
  using string_tree = fcppt::container::tree::object<std::string>;

  string_tree tree("a");

  fcppt::reference<string_tree> const child{tree.push_back(std::string("b"))};

  child.get().push_back(std::string("c"));

  tree.push_back(std::string("d"));

  tree.push_back(std::string("e"));

  std::ostringstream oss{}; // NOLINT(fuchsia-default-arguments-calls)

  oss << tree;

  CHECK(
      oss.str() == "a\n"
                   "\tb\n"
                   "\t\tc\n"
                   "\td\n"
                   "\te\n");
}
