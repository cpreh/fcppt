//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[foreach_enumerator
#include <fcppt/foreach_enumerator.hpp>
#include <fcppt/foreach_enumerator_start.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

namespace
{

namespace my_enum
{
enum type // the nested name type is important
{
	foo,
	bar,
	baz,
	size // note the additional size, which is needed for FOREACH_ENUMERATOR to work
};
}

void
do_something(
	my_enum::type const val
)
{
	fcppt::io::cout
		<< static_cast<unsigned long>(val) // necessary to silence a warning about promotions
		<< FCPPT_TEXT(' ');
}

}

int main()
{
	// outputs 0, 1, 2
	FCPPT_FOREACH_ENUMERATOR(
		i,
		my_enum
	)
		do_something(i);

	fcppt::io::cout << FCPPT_TEXT('\n');

	// it is also possible to dictate the start value
	// prints 1, 2
	FCPPT_FOREACH_ENUMERATOR_START(
		i,
		my_enum,
		my_enum::bar
	)
		do_something(i);

	fcppt::io::cout << FCPPT_TEXT('\n');
}
//]
