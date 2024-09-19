//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/container/bitfield/object.hpp>
#include <fcppt/container/bitfield/operators.hpp>
#include <fcppt/enum/define_max_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <fcppt/config/external_end.hpp>

//! [bitfield]
namespace
{
enum class person_status : std::uint8_t
{
  hungry,
  tired
};
}
FCPPT_ENUM_DEFINE_MAX_VALUE(person_status::tired)

namespace
{
using bitfield = fcppt::container::bitfield::object<person_status>;

void output(bitfield const &_field)
{
  std::cout << "Person status: hungry: " << (_field & person_status::hungry) << '\n'
            << "Person status: tired: " << (_field & person_status::tired) << '\n';
}
}

int main()
{
  // Initialize the bitfield to all zeros
  bitfield field(bitfield::null());

  output(field);

  // Set a flag, the bitwise kind of way
  field |= person_status::hungry;

  output(field);

  // And unset it again
  field &= ~bitfield{person_status::hungry};

  // You can access a single flag via operator[]
  std::cout << "person is hungry: " << field[person_status::hungry] << '\n';

  // You can also set a flag this way:
  field[person_status::hungry] = false;

  std::cout << ("person is hungry: ") << field[person_status::hungry] << '\n';
}
//! [bitfield]
