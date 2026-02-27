//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/reference_impl.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::tree output", "[container],[tree]")
{
  using string_tree = fcppt::container::tree::object<std::string>;

  string_tree tree("a");

  fcppt::reference<string_tree> const child{tree.push_back(std::string("b"))};

  child.get().push_back(std::string("c"));

  tree.push_back(std::string("d"));

  tree.push_back(std::string("e"));

  std::ostringstream oss{};

  oss << tree;

  CHECK(
      oss.str() == "a\n"
                   "\tb\n"
                   "\t\tc\n"
                   "\td\n"
                   "\te\n");
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
