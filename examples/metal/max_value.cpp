//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/metal/max_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace
{
//! [metal_max_value]
// Calculate the maximum size of all the types
typedef
metal::list<
	short,
	int,
	long
>
types;

template<
	typename Type
>
using
sizeof_
=
std::integral_constant<
	std::size_t,
	sizeof(Type)
>;

typedef
fcppt::metal::max_value<
	metal::transform<
		metal::lambda<
			sizeof_
		>,
		types
	>
>
result;

static_assert(
	std::is_same_v<
		result,
		sizeof_<
			long
		>
	>,
	""
);
//! [metal_max_value]
}

int
main()
{
}
