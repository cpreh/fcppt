//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/metal/set/make.hpp>
#include <fcppt/metal/set/to_list.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	fcppt::metal::set::to_list<
		fcppt::metal::set::make<
			int,
			bool
		>
	>
	list;

	static_assert(
		::metal::contains<
			list,
			int
		>::value
	);

	static_assert(
		::metal::contains<
			list,
			bool
		>::value
	);
}
