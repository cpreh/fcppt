//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/map_values_ref.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::map_values_ref", "[container]")
{
  using string_vector_ref = std::vector<fcppt::reference<std::string>>;

  using string_vector_cref = std::vector<fcppt::reference<std::string const>>;

  using int_string_map = std::map<int, std::string>;

  int_string_map map{std::make_pair(1, "test1"), std::make_pair(2, "test2")};

  CHECK(
      fcppt::container::map_values_ref<string_vector_ref>(map) ==
      string_vector_ref{fcppt::make_ref(map[1]), fcppt::make_ref(map[2])});

  CHECK(
      fcppt::container::map_values_ref<string_vector_cref>(map) ==
      string_vector_cref{fcppt::make_cref(map[1]), fcppt::make_cref(map[2])});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
