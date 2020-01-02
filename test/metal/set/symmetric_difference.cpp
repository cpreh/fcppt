//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/metal/set/contains.hpp>
#include <fcppt/metal/set/make.hpp>
#include <fcppt/metal/set/symmetric_difference.hpp>


int
main()
{
	typedef
	fcppt::metal::set::symmetric_difference<
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
		!fcppt::metal::set::contains<
			result,
			int
		>::value,
		"Set contains int"
	);

	static_assert(
		fcppt::metal::set::contains<
			result,
			short
		>::value,
		"Set does not contain short"
	);

	static_assert(
		fcppt::metal::set::contains<
			result,
			long
		>::value,
		"Set does not contain long"
	);
}
