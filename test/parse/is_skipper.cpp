//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/not.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/int.hpp>
#include <fcppt/parse/is_skipper.hpp>


int
main()
{
	static_assert(
		fcppt::parse::is_skipper<
			fcppt::parse::epsilon
		>::value
	);

	static_assert(
		fcppt::not_(
			fcppt::parse::is_skipper<
				fcppt::parse::int_<
					int
				>
			>::value
		)
	);
}
