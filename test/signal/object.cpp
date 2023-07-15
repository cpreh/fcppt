//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/range/size.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/base.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace
{
using signal_type = fcppt::signal::object<void()>;

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("signal::object", "[signal]")
{
  int counter{0};

  auto const add([&counter](int const _value) { counter += _value; });

  auto const con_size(
      [](signal_type const &_sig) { return fcppt::range::size(_sig.connections()); });

  signal_type sig{};

  REQUIRE(sig.empty());

  {
    fcppt::signal::auto_connection const con1(
        sig.connect(signal_type::function{[&add] { add(1); }}));

    CHECK(con_size(sig) == 1U);

    REQUIRE(counter == 0);

    sig();

    REQUIRE(counter == 1);

    {
      fcppt::signal::auto_connection const con2(
          sig.connect(signal_type::function{[&add] { add(2); }}));

      CHECK(con_size(sig) == 2U);

      sig();

      REQUIRE(counter == 4);
    }

    CHECK(con_size(sig) == 1U);
  }

  CHECK(con_size(sig) == 0U);

  REQUIRE(sig.empty());

  sig();

  REQUIRE(counter == 4);
}

TEST_CASE("signal::object move", "[signal]")
{
  signal_type sig{};

  int counter{0};

  fcppt::signal::auto_connection const con1(
      sig.connect(signal_type::function{[&counter] { ++counter; }}));

  signal_type sig2(std::move(sig));

  CHECK(counter == 0);

  sig2();

  CHECK(counter == 1);

  sig = std::move(sig2);

  sig();

  CHECK(counter == 2);

  CHECK(counter == 2);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
