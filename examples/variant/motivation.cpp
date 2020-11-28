//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/variant/match.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace
{
void variant_union()
{
  //! [variant_union]
  union int_or_float
  {
    int i;
    float f;
  };

  int_or_float var; // NOLINT(cppcoreguidelines-pro-type-member-init,hicpp-member-init)

  // Undefined behaviour because the union doesn't store anything
  // std::cout << var.i << '\n';

  // Ok, but doesn't track that the type is int
  // NOLINTNEXTLINE(cppcoreguidelines-pro-type-union-access)
  var.i = 1;

  // Undefined behaviour because the union stores an int
  // std::cout << var.f << '\n';

  auto const print([](int_or_float) {
    // how do we know which type of object is stored?
  });

  print(var);
  //! [variant_union]
}

void variant_example()
{
  //! [variant_example]
  using string_or_int = fcppt::variant::object<std::string, int>;

  auto const print([](string_or_int const &_v) {
    fcppt::variant::match(
        _v,
        [](std::string const &_str) { std::cout << "We have a string " << _str << '\n'; },
        [](int const _i) { std::cout << "We have an int " << _i << '\n'; });
  });

  string_or_int const var(std::string("Hello World"));

  print(var);
  //! [variant_example]
}

}

int main()
try
{
  variant_union();

  variant_example();
}
catch (std::exception const &_error)
{
  std::cerr << _error.what() << '\n';

  return EXIT_FAILURE;
}
