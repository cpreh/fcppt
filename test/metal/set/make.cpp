//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/metal/set/contains.hpp>
#include <fcppt/metal/set/make.hpp>


int
main()
{
	typedef
	fcppt::metal::set::make<
		int,
		bool
	>
	set;

	static_assert(
		fcppt::metal::set::contains<
			set,
			int
		>::value
	);

	static_assert(
		fcppt::metal::set::contains<
			set,
			bool
		>::value
	);
}
