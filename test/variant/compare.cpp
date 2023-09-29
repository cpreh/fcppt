//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/variant/compare.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace
{
struct compare
{
  template <typename T>
  bool operator()(T const &_a, T const &_b) const
  {
    return _a == _b;
  }
};

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("variant::compare", "[variant]")
{
  using variant = fcppt::variant::object<bool, int, std::string>;

  std::string const string("hello world");

  variant const v1(string);

  variant const v2(string);

  CHECK(fcppt::variant::compare(v1, v2, compare()));

  variant const v3(42);

  CHECK_FALSE(fcppt::variant::compare(v1, v3, compare()));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
