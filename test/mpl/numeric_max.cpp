//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/mpl/numeric_max.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		fcppt::mpl::numeric_max<
			unsigned
		>::value
		==
		std::numeric_limits<
			unsigned
		>::max(),
		""
	);
}
