//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/bitfield/comparison.hpp>
#include <fcppt/container/bitfield/object.hpp>
#include <fcppt/container/bitfield/object_from_enum.hpp>
#include <fcppt/container/bitfield/std_hash.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_bitfield_hash
)
{
FCPPT_PP_POP_WARNING

	enum class test_enum
	{
		test1,
		test2,
		fcppt_maximum = test2
	};

	typedef
	fcppt::container::bitfield::object_from_enum<
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

	BOOST_CHECK_EQUAL(
		values.count(
			bitfield{
				test_enum::test1,
				test_enum::test2
			}
		),
		1u
	);

	BOOST_CHECK_EQUAL(
		values.count(
			bitfield{
				test_enum::test1
			}
		),
		1u
	);

	BOOST_CHECK_EQUAL(
		values.count(
			bitfield{
				test_enum::test2
			}
		),
		0u
	);
}
