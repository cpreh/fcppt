//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[bitfield
#include <fcppt/container/bitfield/bitfield.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <boost/foreach.hpp>

namespace
{
// We use the enum namespace pattern here
namespace person_status
{
enum type
{
	hungry,
	tired,
	size // note the extra field here
};
}

typedef
fcppt::container::bitfield::basic<person_status::type,person_status::size>
bitfield;

void
output(
	bitfield const &b
)
{
	fcppt::io::cout 
		<< FCPPT_TEXT("Person status: hungry: ") << (b & person_status::hungry)
		<< FCPPT_TEXT('\n')
		<< FCPPT_TEXT("Person status: tired: ") << (b & person_status::tired)
		<< FCPPT_TEXT('\n');
}
}

int main()
{
	// Initialize the bitfield to all zeros
	bitfield b(
		bitfield::null()
	);

	output(b);

	// Set a flag, the bitwise kind of way
	b |= person_status::hungry;

	output(b);

	// And unset it again
	b &= ~bitfield(person_status::hungry);

	// You can access a single flag via operator[]
	fcppt::io::cout
		<< FCPPT_TEXT("person is hungry: ")
		<< b[person_status::hungry]
		<< FCPPT_TEXT('\n');

	// You can also set a flag this way:
	b[person_status::hungry] = false;

	fcppt::io::cout
		<< FCPPT_TEXT("person is hungry: ")
		<< b[person_status::hungry]
		<< FCPPT_TEXT('\n');

	// Iterate through the field
	BOOST_FOREACH(bitfield::const_reference r,b)
		fcppt::io::cout
			<< r
			<< FCPPT_TEXT('\n');
}
//]
