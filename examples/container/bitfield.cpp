//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/container/bitfield/object_from_enum.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/io/cout.hpp>

//! [bitfield]

namespace
{

enum class person_status
{
	hungry,
	tired,
	fcppt_maximum = tired // note the extra field here
};

typedef
fcppt::container::bitfield::object_from_enum<
	person_status
>
bitfield;

void
output(
	bitfield const &_field
)
{
	fcppt::io::cout()
		<< FCPPT_TEXT("Person status: hungry: ")
		<< (_field & person_status::hungry)
		<< FCPPT_TEXT('\n')
		<< FCPPT_TEXT("Person status: tired: ")
		<< (_field & person_status::tired)
		<< FCPPT_TEXT('\n');
}
}

int main()
{
	// Initialize the bitfield to all zeros
	bitfield field(
		bitfield::null()
	);

	output(field);

	// Set a flag, the bitwise kind of way
	field |= person_status::hungry;

	output(field);

	// And unset it again
	field &= ~bitfield{person_status::hungry};

	// You can access a single flag via operator[]
	fcppt::io::cout()
		<< FCPPT_TEXT("person is hungry: ")
		<< field[person_status::hungry]
		<< FCPPT_TEXT('\n');

	// You can also set a flag this way:
	field[person_status::hungry] = false;

	fcppt::io::cout()
		<< FCPPT_TEXT("person is hungry: ")
		<< field[person_status::hungry]
		<< FCPPT_TEXT('\n');
}
//! [bitfield]
