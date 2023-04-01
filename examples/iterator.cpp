//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/get.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/iterator/base_impl.hpp>
#include <fcppt/iterator/types_fwd.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <fcppt/config/external_end.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

namespace
{
// ![iterator_types]
class my_iterator;

using iterator_types = fcppt::iterator::types<
    my_iterator, // The derived type
    int, // The value type
    int &, // The reference type, which is non const so the iterator is also an output iterator
    std::ptrdiff_t, // The difference type for pointers
    std::random_access_iterator_tag // The iterator category
    >;
// ![iterator_types]

// ![iterator_impl]
class my_iterator : public fcppt::iterator::base<iterator_types>
{
public:
  // Random access iterators require a default constructor.
  my_iterator() : ptr_{nullptr} {}

  explicit my_iterator(pointer const _ptr) : ptr_{_ptr} {}

  [[nodiscard]] reference operator*() const { return *ptr_; }

  void increment() { ++ptr_; }

  [[nodiscard]] bool equal(my_iterator const &_other) const { return ptr_ == _other.ptr_; }

  void decrement() { --ptr_; }

  void advance(difference_type const _distance) { ptr_ += _distance; }

  [[nodiscard]] difference_type distance_to(my_iterator const &_other) const
  {
    return _other.ptr_ - ptr_;
  }

private:
  pointer ptr_;
};
// ![iterator_impl]
}

int main()
{
  // ![iterator_example]
  fcppt::array::object<int, 3> array{1, 2, 3};

  my_iterator const start(&*array.begin());

  my_iterator it{start};

  ++it;

  *it = 0;

  // Array is now {1,5,3}

  // Prints 5
  std::cout << fcppt::array::get<1U>(array) << '\n';

  // Prints 1
  std::cout << (it - start) << '\n';
  // ![iterator_example]

  my_iterator const dummy{};

  std::cout << (start == it) << '\n';

  --it;

  it += 1;
}

FCPPT_PP_POP_WARNING
