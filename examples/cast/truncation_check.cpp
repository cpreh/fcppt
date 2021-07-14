//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/truncation_check.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <limits>
#include <fcppt/config/external_end.hpp>

namespace
{
//! [truncation_check_cast_int_long]
void check_int_long()
{
  // Try to cast the greatest unsigned long value into an unsigned int.
  // This might fail or it might not fail depending on the
  // implementation.
  // An empty optional will be returned on failure.
  auto const result(fcppt::cast::truncation_check<unsigned>(
      std::numeric_limits<unsigned long // NOLINT(google-runtime-int)
                          >::max()));

  std::cout << "The casted value is " << result << '\n';
}
//! [truncation_check_cast_int_long]

//! [truncation_check_cast_negative]
void negative_conversion()
{
  // -1 cannot be represented as an unsigned. This will return nothing.
  auto const result(fcppt::cast::truncation_check<unsigned>(-1));

  std::cout << "The casted value is " << result << '\n';
}
//! [truncation_check_cast_negative]

}

int main()
{
  check_int_long();

  negative_conversion();
}
//]
