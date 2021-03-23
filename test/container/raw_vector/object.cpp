//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/object_impl.hpp>
#include <fcppt/container/raw_vector/comparison.hpp>
#include <fcppt/container/raw_vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <iterator>
#include <sstream>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace
{
using int_vector = fcppt::container::raw_vector::object<int>;

}

template class fcppt::container::raw_vector::object<int>;

TEST_CASE("container::raw_vector::shrink_to_fit", "[container],[raw_vector]")
{
  int_vector test{};

  test.resize(100U, 0);

  test.reserve(1000U);

  CHECK(test.capacity() >= 1000U);

  test.shrink_to_fit();

  CHECK(test.capacity() == 100U);

  CHECK(test.size() == 100U);
}

TEST_CASE("container::raw_vector shrink"
          "[container],[raw_vector]")
{
  int_vector test(10U, 0);

  CHECK(test.size() == 10U);

  test.resize(5U, 0);

  CHECK(test.size() == 5U);
}

TEST_CASE("container::raw_vector::insert", "[container],[raw_vector]")
{
  int_vector test{};

  test.push_back(10);

  test.push_back(20);

  REQUIRE(test.size() == 2U);

  test.insert(test.begin() + 1U, 30);

  REQUIRE(test == int_vector{10, 30, 20});

  test.insert(test.begin() + 2, 2U, 40);

  CHECK(test == int_vector{10, 30, 40, 40, 20});
}

TEST_CASE("container::raw_vector insert iterator", "[container],[raw_vector]")
{
  int_vector test{};

  using int_array = fcppt::array::object<int, 5>;

  int_array const array{0, 1, 2, 3, 4};

  test.insert(test.begin(), array.begin(), array.end());

  CHECK(test == int_vector{0, 1, 2, 3, 4});

  std::stringstream stream{}; // NOLINT(fuchsia-default-arguments-calls)

  stream << 10 << ' ' << 20 << ' ' << 30 << ' ' << 40 << ' ' << 50;

  test.insert(test.end(), std::istream_iterator<int>(stream), std::istream_iterator<int>());

  CHECK(stream.eof());

  CHECK(test == int_vector{0, 1, 2, 3, 4, 10, 20, 30, 40, 50});
}

TEST_CASE("container::raw_vector::push_back", "[container],[raw_vector]")
{
  int_vector test{};

  for (int_vector::value_type i{0}; i < 50; ++i)
  {
    test.push_back(i);
  }

  for (int_vector::size_type i{0}; i < test.size(); ++i)
  {
    CHECK(test[i] == static_cast<int_vector::value_type>(i));
  }
}

TEST_CASE("container::raw_vector::erase", "[container],[raw_vector]")
{
  int_vector test{};

  for (int_vector::value_type i{0}; i < 5; ++i)
  {
    test.push_back(i);
  }

  REQUIRE(test.size() == 5U);

  test.erase(test.begin() + 3);

  CHECK(test == int_vector{0, 1, 2, 4});

  test.erase(test.begin() + 1, test.begin() + 3);

  CHECK(test == int_vector{0, 4});

  test.clear();

  CHECK(test.empty());
}

TEST_CASE("container::raw_vector move", "[container],[raw_vector]")
{
  int_vector test1(100U, 0);

  test1[0] = 500;

  int_vector test2(std::move(test1));

  REQUIRE(test2.size() == 100U);

  CHECK(test2[0] == 500);

  int_vector test3{};

  test3 = std::move(test2);

  REQUIRE(test3.size() == 100U);

  CHECK(test3[0] == 500);
}

TEST_CASE("container::raw_vector initializer_list", "[container],[raw_vector]")
{
  int_vector const test1{1, 2, 3};

  REQUIRE(test1.size() == 3U);

  CHECK(test1[0] == 1);

  CHECK(test1[1] == 2);

  CHECK(test1[2] == 3);
}
