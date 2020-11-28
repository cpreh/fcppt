//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/variant/apply.hpp>
#include <fcppt/variant/get_exn.hpp>
#include <fcppt/variant/invalid_get.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace
{
//! [variant_nonconst_visitor]
struct visitor
{
  // operator() takes T as non const ref
  template <typename T>
  void operator()(T &_val) const
  {
    // reset _val to the default value
    _val = T();
  }
};
//! [variant_nonconst_visitor]
}

int main()
try
{
  // typedef a variant that can either hold a string or an int
  using string_or_int = fcppt::variant::object<std::string, int>;

  //! [variant_nonconst_visitation]
  string_or_int v(std::string("Hello World"));

  fcppt::variant::apply(visitor(), v);

  // only prints a newline because the string contains nothing anymore
  std::cout << fcppt::variant::get_exn<std::string>(v) << '\n';
  //! [variant_nonconst_visitation]

  fcppt::variant::get_exn<int>(v);

  return EXIT_SUCCESS;
}
catch (fcppt::variant::invalid_get const &_error)
{
  fcppt::io::cerr() << _error.string() << FCPPT_TEXT('\n');

  return EXIT_SUCCESS;
}
catch (std::exception const &_error)
{
  std::cerr << _error.what() << '\n';

  return EXIT_FAILURE;
}
