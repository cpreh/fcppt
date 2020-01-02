//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/no_init.hpp>
#include <fcppt/container/bitfield/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::bitfield empty",
	"[container],[bitfield]"
)
{
	typedef
	std::integral_constant<
		unsigned,
		0
	>
	static_size;

	typedef
	fcppt::container::bitfield::object<
		unsigned,
		static_size
	>
	empty_bitfield;

	CHECK(
		empty_bitfield{
			fcppt::no_init()
		}.array().empty()
	);

	static_assert(
		empty_bitfield::static_size::value
		==
		0u,
		""
	);
}
