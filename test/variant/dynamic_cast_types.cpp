//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/reference_impl.hpp>
#include <fcppt/variant/dynamic_cast_types.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/at.hpp>
#include <brigand/sequences/list.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	fcppt::variant::dynamic_cast_types<
		brigand::list<
			int,
			char const
		>
	>
	types;

	static_assert(
		std::is_same<
			brigand::at_c<
				types,
				0
			>,
			fcppt::reference<
				int
			>
		>::value,
		""
	);

	static_assert(
		std::is_same<
			brigand::at_c<
				types,
				1
			>,
			fcppt::reference<
				char const
			>
		>::value,
		""
	);
}
