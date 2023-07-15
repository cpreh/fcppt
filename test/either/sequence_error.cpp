//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/error.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/either/no_error_comparison.hpp>
#include <fcppt/either/no_error_output.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/either/sequence_error.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("either::sequence_error", "[either]")
{
  using either_error = fcppt::either::error<std::string>;

  CHECK(fcppt::either::sequence_error(std::vector<int>{1, 2, 3}, [](int const _value) {
          return _value % 2 == 0 ? either_error{std::string{"test"}}
                                 : either_error{fcppt::either::no_error{}};
        }) == either_error{std::string{"test"}});

  CHECK(
      fcppt::either::sequence_error(
          fcppt::container::make<std::vector<fcppt::unique_ptr<int>>>(
              fcppt::make_unique_ptr<int>(2), fcppt::make_unique_ptr<int>(4)),
          [](fcppt::unique_ptr<int> &&_value) {
            return *_value % 2 == 0 ? either_error{fcppt::either::no_error{}}
                                    : either_error{std::string{"test"}};
          }) == either_error{fcppt::either::no_error{}});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
