//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/metal/set/make.hpp>
#include <fcppt/metal/set/has_key.hpp>
#include <fcppt/metal/set/union.hpp>


int
main()
{
	typedef
	fcppt::metal::set::union_<
		fcppt::metal::set::make<
			short,
			int
		>,
		fcppt::metal::set::make<
			int,
			long
		>
	>
	result;

	static_assert(
		fcppt::metal::set::has_key<
			result,
			int
		>::value,
		"Set does not contain int"
	);

	static_assert(
		fcppt::metal::set::has_key<
			result,
			short
		>::value,
		"Set does not contain short"
	);

	static_assert(
		fcppt::metal::set::has_key<
			result,
			long
		>::value,
		"Set does not contain long"
	);
}
