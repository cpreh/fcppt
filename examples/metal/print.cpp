//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/metal/print.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
//! [metal_print}
	typedef
	metal::list<
		int,
		float,
		double
	>
	vec;

	// prints (int, float, double) to cout
	fcppt::metal::print<
		vec
	>(
		fcppt::io::cout()
	)
	<<
	FCPPT_TEXT('\n');
//! [metal_print}
}
