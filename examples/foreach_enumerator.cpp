//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/foreach_enumerator.hpp>
#include <fcppt/foreach_enumerator_start.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>


namespace
{

// ![foreach_enumerator_declaration]
namespace my_enum
{
enum type // the nested name type is important
{
	enum0,
	enum1,
	enum2,
	enum3,
	size // note the additional size, which is needed for FOREACH_ENUMERATOR to work
};
}
// ![foreach_enumerator_declaration]

void
print_enum_value(
	my_enum::type const val
)
{
	fcppt::io::cout()
		<< static_cast<unsigned long>(val) // necessary to silence a warning about promotions
		<< FCPPT_TEXT(' ');
}

}

int
main()
{
//! [foreach_enumerator]
	// Iterates over (enum0, enum1, enum2, enum3)
	// Prints 0, 1, 2, 3
	FCPPT_FOREACH_ENUMERATOR(
		loop_var,
		my_enum
	)
		print_enum_value(
			loop_var
		);
//! [foreach_enumerator]

	fcppt::io::cout()
		<< FCPPT_TEXT('\n');

//! [foreach_enumerator_start]
	// Iterates over (enum1, enum2, enum3).
	// Prints 1, 2, 3
	FCPPT_FOREACH_ENUMERATOR_START(
		loop_var,
		my_enum,
		my_enum::enum1
	)
		print_enum_value(
			loop_var
		);
//! [foreach_enumerator_start]

	fcppt::io::cout()
		<< FCPPT_TEXT('\n');

//! [foreach_enumerator_start_end]
	// Iterates over (enum2, enum3).
	// Prints 1, 2
	FCPPT_FOREACH_ENUMERATOR_START_END(
		loop_var,
		my_enum,
		my_enum::enum1,
		my_enum::enum3
	)
		print_enum_value(
			loop_var
		);
//! [foreach_enumerator_start_end]

	fcppt::io::cout()
		<< FCPPT_TEXT('\n');
}
//]
