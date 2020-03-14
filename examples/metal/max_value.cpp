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
using
types
=
metal::list<
	short, // NOLINT(google-runtime-int)
	int, // NOLINT(google-runtime-int)
	long // NOLINT(google-runtime-int)
>;

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

using
result
=
fcppt::metal::max_value<
	metal::transform<
		metal::lambda<
			sizeof_
		>,
		types
	>
>;

static_assert(
	std::is_same_v<
		result,
		sizeof_<
			long // NOLINT(google-runtime-int)
		>
	>
);
//! [metal_max_value]
}

int
main()
{
}
