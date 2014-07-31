//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/enum_max_value.hpp>
#include <fcppt/make_enum_range.hpp>
#include <fcppt/cast/enum_to_underlying.hpp>
#include <fcppt/container/enum_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


namespace
{

//! [enum_maximum]
enum class myenum
{
	val1,
	val2,
	fcppt_maximum = val2
};

void
print_enum(
	myenum const _value
)
{
	std::cout
		<<
		// Convert to an integer
		fcppt::cast::enum_to_underlying(
			_value
		)
		<< '\n';

}

void
print()
{
	print_enum(
		fcppt::enum_max_value<
			myenum
		>::value
	);
}
//! [enum_maximum]

void
iterate()
{
// ![enum_range]
	// Prints 0, 1
	for(
		myenum const value
		:
		fcppt::make_enum_range<
			myenum
		>()
	)
		print_enum(
			value
		);
// ![enum_range]
}

void
enum_array()
{
// ![enum_array]
	typedef
	fcppt::container::enum_array<
		myenum,
		bool
	>
	array;

	// Requires three {} pairs because the array wraps std::array
	// internally
	array const val{{{
		true,
		false
	}}};

	std::cout << (val[myenum::val1]) << '\n';
// ![enum_array]
}

}

int
main()
{
	print();

	iterate();

	enum_array();
}
