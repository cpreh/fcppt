//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

int
main()
{
// ![init_points]
	using
	box2i
	=
	fcppt::math::box::object<
		unsigned,
		2
	>;

	box2i const box(
		box2i::vector(
			1U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			2U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		),
		box2i::vector(
			2U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			3U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		)
	);
// ![init_points]

// ![init_size]
	box2i const box2(
		box2i::vector(
			1U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			2U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		),
		box2i::dim(
			1U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			1U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		)
	);
// ![init_size]

	std::cout << box << '\n';

	std::cout << box2 << '\n';

// ![getters]
	std::cout << box.pos() << ", " << box.max() << '\n';
	std::cout << box.pos() << ", " << box.size() << '\n';
// ![getters]

}
//]
