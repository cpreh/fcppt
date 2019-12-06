//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/metal/index_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	metal::list<
		int,
		float
	>
	list;

	static_assert(
		std::is_same_v<
			fcppt::metal::index_of<
				list,
				int
			>,
			metal::number<
				0
			>
		>
	);

	static_assert(
		std::is_same_v<
			fcppt::metal::index_of<
				list,
				float
			>,
			metal::number<
				1
			>
		>
	);
}
