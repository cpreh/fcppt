//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tuple/move_element.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		fcppt::container::tuple::move_element<
			std::tuple<
				int
			>,
			0
		>::value,
		"std::tuple<int> should be moved"
	);

	static_assert(
		fcppt::container::tuple::move_element<
			std::tuple<
				int
			> &&,
			0
		>::value,
		"std::tuple<int> && should be moved"
	);

	static_assert(
		fcppt::container::tuple::move_element<
			std::tuple<
				int &&
			> &,
			0
		>::value,
		"std::tuple<int &&> & should be moved"
	);

	static_assert(
		!fcppt::container::tuple::move_element<
			std::tuple<
				int &
			> &&,
			0
		>::value,
		"std::tuple<int &> && should not be moved"
	);
}
