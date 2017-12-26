//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/brigand/found_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	brigand::list<
		int,
		float
	>
	list;

	static_assert(
		fcppt::brigand::found_t<
			list,
			int
		>::value,
		"int not found"
	);

	static_assert(
		fcppt::brigand::found_t<
			list,
			float
		>::value,
		"float not found"
	);

	static_assert(
		!fcppt::brigand::found_t<
			list,
			char
		>::value,
		"char found"
	);
}
