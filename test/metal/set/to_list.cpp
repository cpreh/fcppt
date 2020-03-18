//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/metal/contains.hpp>
#include <fcppt/metal/set/make.hpp>
#include <fcppt/metal/set/to_list.hpp>


int
main()
{
	using
	list
	=
	fcppt::metal::set::to_list<
		fcppt::metal::set::make<
			int,
			bool
		>
	>;

	static_assert(
		fcppt::metal::contains<
			list,
			int
		>::value
	);

	static_assert(
		fcppt::metal::contains<
			list,
			bool
		>::value
	);
}
