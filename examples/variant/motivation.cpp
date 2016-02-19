//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/get_unsafe.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <iostream>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{

void
variant_union()
{
//! [variant_union]
	union int_or_float
	{
		int i;
		float f;
	};

	int_or_float var;

	// Undefined behaviour because the union doesn't store anything
	//std::cout << var.i << '\n';

	// Ok, but doesn't track that the type is int
	var.i = 42;

	// Undefined behaviour because the union stores an int
	//std::cout << var.f << '\n';

	auto const print(
		[](
			int_or_float
		)
		{
			// how do we know which type of object is stored?
		}
	);

	print(
		var
	);

	/*
	// Doesn't work in C++03
	union string_or_int
	{
		std::string s;
		int i;
	};*/

//! [variant_union]
}

void
variant_example()
{
//! [variant_example]
	// Note that an MPL sequence is used here to describe which types the
	// variant can hold. Alternatively, fcppt::variant::variadic can be
	// used.
	typedef
	fcppt::variant::object<
		boost::mpl::vector2<
			std::string,
			int
		>
	>
	string_or_int;


	auto const print(
		[](
			string_or_int x
		)
		{
			// fcppt::variant::holds_type queries if the type is held by the
			// variant
			if(
				fcppt::variant::holds_type<std::string>(x)
			)
				std::cout << fcppt::variant::get_unsafe<std::string>(x) << '\n';
			else if(
				fcppt::variant::holds_type<int>(x)
			)
				std::cout << fcppt::variant::get_unsafe<int>(x) << '\n';
		}
	);

	string_or_int var(
		std::string(
			"Hello World"
		)
	);

	print(
		var
	);
//! [variant_example]
}

}

int
main()
{
	variant_union();

	variant_example();
}
