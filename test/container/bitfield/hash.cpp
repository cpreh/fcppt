//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/bitfield/comparison.hpp>
#include <fcppt/container/bitfield/enum_object.hpp>
#include <fcppt/container/bitfield/std_hash.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::bitfield hash",
	"[container],[bitfield]"
)
{
	enum class test_enum
	{
		test1,
		test2,
		fcppt_maximum = test2
	};

	typedef
	fcppt::container::bitfield::enum_object<
		test_enum
	>
	bitfield;

	typedef
	std::unordered_set<
		bitfield
	>
	bitfield_set;

	bitfield_set const values{
		bitfield{
			test_enum::test1
		},
		bitfield{
			test_enum::test1,
			test_enum::test2
		}
	};

	CHECK(
		values.count(
			bitfield{
				test_enum::test1,
				test_enum::test2
			}
		)
		==
		1u
	);

	CHECK(
		values.count(
			bitfield{
				test_enum::test1
			}
		)
		==
		1u
	);

	CHECK(
		values.count(
			bitfield{
				test_enum::test2
			}
		)
		==
		0u
	);
}
