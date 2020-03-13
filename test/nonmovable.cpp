//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/nonmovable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace
{

struct test
{
	FCPPT_NONMOVABLE(
		test
	);
};

}

int
main()
{
	static_assert(
		!std::is_move_constructible_v<
			test
		>
	);

	static_assert(
		!std::is_move_assignable_v<
			test
		>
	);

	static_assert(
		!std::is_copy_constructible_v<
			test
		>
	);

	static_assert(
		!std::is_assignable_v<
			test,
			test
		>
	);
}
