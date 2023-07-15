//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/map_iteration.hpp>
#include <fcppt/algorithm/update_action.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <map>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("algorithm map_iteration", "[algorithm_map_iteration]")
{
  using sequence = std::map<int, std::string>;

  sequence seq{
      std::make_pair(1, std::string("1")),
      std::make_pair(2, std::string("2")),
      std::make_pair(3, std::string("3")),
      std::make_pair(4, std::string("4"))};

  fcppt::algorithm::map_iteration(seq, [](std::pair<int, std::string> const &_value) {
    return _value.first % 2 == 0 ? fcppt::algorithm::update_action::keep
                                 : fcppt::algorithm::update_action::remove;
  });

  CHECK(seq == sequence{std::make_pair(2, "2"), std::make_pair(4, "4")});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
