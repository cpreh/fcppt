//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/variant/get_unsafe.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("variant move", "[variant]")
{
  using int_unique_ptr = fcppt::unique_ptr<int>;

  using variant = fcppt::variant::object<int_unique_ptr, std::string>;

  variant test(fcppt::make_unique_ptr<int>(1));

  CHECK(*fcppt::variant::get_unsafe<int_unique_ptr>(test) == 1);

  variant test2(std::move(test));

  CHECK(*fcppt::variant::get_unsafe<int_unique_ptr>(test2) == 1);

  variant test3(std::string("test"));

  variant test4(std::string("test2"));

  test4 = std::move(test3);

  CHECK(fcppt::variant::get_unsafe<std::string>(test4) == std::string("test"));

  test4 = std::move(test2);

  CHECK(*fcppt::variant::get_unsafe<int_unique_ptr>(test4) == 1);
}

TEST_CASE("variant move nested", "[variant]")
{
  using variant_unique_ptr = fcppt::variant::object<fcppt::unique_ptr<int>>;

  using nested = fcppt::variant::object<variant_unique_ptr>;

  nested test{variant_unique_ptr{fcppt::make_unique_ptr<int>(1)}};

  CHECK(
      *fcppt::variant::get_unsafe<fcppt::unique_ptr<int>>(
          fcppt::variant::get_unsafe<variant_unique_ptr>(test)) == 1);

  nested test2{variant_unique_ptr{fcppt::make_unique_ptr<int>(2)}};

  test2 = std::move(test);

  CHECK(
      *fcppt::variant::get_unsafe<fcppt::unique_ptr<int>>(
          fcppt::variant::get_unsafe<variant_unique_ptr>(test2)) == 1);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
