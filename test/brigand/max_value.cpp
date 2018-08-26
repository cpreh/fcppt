//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/brigand/max_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
std::size_t
size_type;

template<
	size_type Size
>
using
static_size
=
std::integral_constant<
	size_type,
	Size
>;

}

int
main()
{
	static_assert(
		std::is_same<
			fcppt::brigand::max_value<
				brigand::list<
					static_size<
						5u
					>,
					static_size<
						7u
					>,
					static_size<
						3u
					>
				>
			>,
			static_size<
				7u
			>
		>::value,
		""
	);
}
