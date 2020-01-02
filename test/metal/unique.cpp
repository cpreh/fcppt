//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/metal/unique.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


int
main()
{
	{
		typedef
		fcppt::metal::unique<
			metal::list<
				int,
				int
			>
		>
		list;

		static_assert(
			::metal::size<
				list
			>::value
			==
			1u,
			""
		);

		static_assert(
			::metal::contains<
				list,
				int
			>::value,
			""
		);
	}

	{
		typedef
		fcppt::metal::unique<
			metal::list<
				int,
				float
			>
		>
		list;

		static_assert(
			::metal::size<
				list
			>::value
			==
			2u,
			""
		);

		static_assert(
			::metal::contains<
				list,
				int
			>::value,
			""
		);

		static_assert(
			::metal::contains<
				list,
				float
			>::value,
			""
		);
	}
}
