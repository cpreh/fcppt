//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_int_range.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace
{
void coding_style_loop(int const n)
{
  // ![coding_style_loop]
  int result{0};
  for (int i{1}; i < n; ++i)
  {
    result += i;
  }
  // ![coding_style_loop]
}

void coding_style_fold(int const n)
{
  // ![coding_style_fold]
  fcppt::algorithm::fold(
      fcppt::make_int_range(1, n), 0, [](int i, int result) { return i + result; })
      // ![coding_style_fold]
      ;
}

template <typename T>
T from_index(std::size_t const _value)
{
  return static_cast<T>(_value);
}

// ![coding_style_make_array]
template <typename T, std::size_t N>
fcppt::array::object<T, N> make_array();
// ![coding_style_make_array]

template <typename T, std::size_t N>
fcppt::array::object<T, N> make_array()
{
  // ![coding_style_array_init]
  return fcppt::array::init<fcppt::array::object<T, N>>(
      [](std::size_t i) { return from_index<T>(i); });
  // ![coding_style_array_init]
}

}

int main()
{
  coding_style_loop(1);

  coding_style_fold(1);

  make_array<int, 4>();
}
