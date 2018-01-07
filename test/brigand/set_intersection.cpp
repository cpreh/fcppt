//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/brigand/set_intersection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/has_key.hpp>
#include <brigand/sequences/set.hpp>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	fcppt::brigand::set_intersection<
		brigand::set<
			short,
			int
		>,
		brigand::set<
			int,
			long
		>
	>
	result;

	static_assert(
		brigand::has_key<
			result,
			int
		>::value,
		"Set does not contain int"
	);

	static_assert(
		!brigand::has_key<
			result,
			short
		>::value,
		"Set contains short"
	);

	static_assert(
		!brigand::has_key<
			result,
			long
		>::value,
		"Set contains long"
	);
}
