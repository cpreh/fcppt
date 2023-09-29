//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/strong_typedef_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/algorithm/contains.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/random/generator/minstd_rand.hpp>
#include <fcppt/random/generator/seed_from_chrono.hpp>
#include <fcppt/random/wrapper/make_uniform_container.hpp>
#include <fcppt/random/wrapper/uniform_container.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("random::wrapper::uniform_container", "[random]")
{
  using string_vector = std::vector<std::string>;

  string_vector const strings{std::string("test1"), std::string("test2")};

  auto dist{fcppt::random::wrapper::make_uniform_container(fcppt::make_cref(strings))};

  auto &dist_inner{
      fcppt::optional::to_exception(dist, [] { return std::runtime_error{"Invalid range!"}; })};

  fcppt::random::generator::minstd_rand generator(
      fcppt::random::generator::seed_from_chrono<fcppt::random::generator::minstd_rand::seed>());

  CHECK(fcppt::algorithm::contains(strings, dist_inner(generator)));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
