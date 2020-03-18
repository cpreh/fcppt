//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/not.hpp>
#include <fcppt/metal/set/contains.hpp>
#include <fcppt/metal/set/difference.hpp>
#include <fcppt/metal/set/make.hpp>


int
main()
{
	using
	result
	=
	fcppt::metal::set::difference<
		fcppt::metal::set::make<
			short, //NOLINT(google-runtime-int)
			int
		>,
		fcppt::metal::set::make<
			int,
			long //NOLINT(google-runtime-int)
		>
	>;

	static_assert(
		fcppt::not_(
			fcppt::metal::set::contains<
				result,
				int
			>::value
		),
		"Set contains int"
	);

	static_assert(
		fcppt::metal::set::contains<
			result,
			short //NOLINT(google-runtime-int)
		>::value,
		"Set does not contain short"
	);

	static_assert(
		fcppt::not_(
			fcppt::metal::set::contains<
				result,
				long //NOLINT(google-runtime-int)
			>::value
		),
		"Set contains long"
	);
}
