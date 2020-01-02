//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_traits/is_raw_pointer.hpp>


int
main()
{
	static_assert(
		fcppt::type_traits::is_raw_pointer<
			char *
		>::value,
		"char * is not a raw pointer"
	);

	static_assert(
		fcppt::type_traits::is_raw_pointer<
			unsigned char *
		>::value,
		"char * is not a raw pointer"
	);

	static_assert(
		fcppt::type_traits::is_raw_pointer<
			char const *
		>::value,
		"char * is not a raw pointer"
	);

	static_assert(
		fcppt::type_traits::is_raw_pointer<
			unsigned char const *
		>::value,
		"char * is not a raw pointer"
	);

	static_assert(
		!fcppt::type_traits::is_raw_pointer<
			int *
		>::value,
		"char * is not a raw pointer"
	);

	static_assert(
		!fcppt::type_traits::is_raw_pointer<
			int const *
		>::value,
		"char * is not a raw pointer"
	);
}
