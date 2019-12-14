//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/apply.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <fcppt/config/external_end.hpp>


int
main()
{
	// typedef a variant that can either hold a string or an int
	typedef
	fcppt::variant::object<
		std::string,
		int
	>
	string_or_int;

//! [variant_binary_visitation]
	string_or_int const v(
		std::string(
			"Hello World"
		)
	);

	string_or_int const u(
		42
	);

	// Does a binary visitation.
	// Prints "Hello World" 42.
	fcppt::variant::apply(
		[](
			auto const &_val1,
			auto const &_val2
		)
		{
			std::cout
				<< _val1
				<< ' '
				<< _val2
				<< '\n';
		},
		v,
		u
	);
//! [variant_binary_visitation]
}
