//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/brigand/found_t.hpp>
#include <fcppt/brigand/unique.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/size.hpp>
#include <fcppt/config/external_end.hpp>


int
main()
{
	{
		typedef
		fcppt::brigand::unique<
			brigand::list<
				int,
				int
			>
		>
		list;

		static_assert(
			::brigand::size<
				list
			>::value
			==
			1u,
			""
		);

		static_assert(
			fcppt::brigand::found_t<
				list,
				int
			>::value,
			""
		);
	}

	{
		typedef
		fcppt::brigand::unique<
			brigand::list<
				int,
				float
			>
		>
		list;

		static_assert(
			::brigand::size<
				list
			>::value
			==
			2u,
			""
		);

		static_assert(
			fcppt::brigand::found_t<
				list,
				int
			>::value,
			""
		);

		static_assert(
			fcppt::brigand::found_t<
				list,
				float
			>::value,
			""
		);
	}
}
