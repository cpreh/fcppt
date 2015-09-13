//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/enum_is_empty.hpp>
#include <fcppt/enum_size.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/container/bitfield/comparison.hpp>
#include <fcppt/container/bitfield/is_subset_eq.hpp>
#include <fcppt/container/bitfield/object_from_enum.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/container/bitfield/std_hash.hpp>
#include <fcppt/container/bitfield/underlying_value.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <type_traits>
#include <unordered_set>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class test_enum
{
	test1,
	test2,
	test3,
	fcppt_maximum = test3
};

typedef fcppt::container::bitfield::object_from_enum<
	test_enum
> bitfield;

enum class empty_enum
{
};

}

namespace fcppt
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<>
struct enum_is_empty<
	empty_enum
>
:
std::true_type
{
};

FCPPT_PP_POP_WARNING

}

typedef fcppt::container::bitfield::object_from_enum<
	empty_enum
> empty_bitfield;

#define FCPPT_INSTANTIATE_BITFIELD(\
	enum_,\
	internal_\
)\
template \
class \
fcppt::container::bitfield::object< \
	enum_, \
	fcppt::enum_size<\
		enum_\
	>::type\
>; \
\
template \
class \
fcppt::container::bitfield::proxy< \
	fcppt::container::bitfield::array< \
		enum_, \
		fcppt::enum_size<\
			enum_\
		>::type,\
		internal_\
	> \
> \

FCPPT_INSTANTIATE_BITFIELD(
	test_enum,
	fcppt::container::bitfield::default_internal_type
);

FCPPT_INSTANTIATE_BITFIELD(
	empty_enum,
	fcppt::container::bitfield::default_internal_type
);

#undef FCPPT_INSTANTIATE_BITFIELD

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_bitfield_arithmetic
)
{
FCPPT_PP_POP_WARNING

	bitfield field1(
		bitfield::null()
	);

	field1[
		test_enum::test1
	] = true;

	bitfield field2(
		bitfield::null()
	);

	BOOST_CHECK(
		(field2 | test_enum::test2)
		& test_enum::test2
	);

	field2[test_enum::test3] = true;

	{
		bitfield const bf_or(
			field1 | field2
		);

		BOOST_CHECK(
			bf_or[test_enum::test1]
			&& !bf_or[test_enum::test2]
			&& bf_or[test_enum::test3]
		);
	}

	BOOST_CHECK(
		(field1 & field2)
		==
		bitfield::null()
	);

	{

		bitfield const bf_xor(
			field1 ^ field2
		);

		BOOST_REQUIRE(
			bf_xor[test_enum::test1]
			&& !bf_xor[test_enum::test2]
			&& bf_xor[test_enum::test3]
		);
	}
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_bitfield_comparison
)
{
FCPPT_PP_POP_WARNING

	bitfield field1(
		bitfield::null()
	);

	bitfield field2(
		bitfield::null()
	);

	BOOST_REQUIRE(
		field1 == field2
	);

	field2[test_enum::test2] = true;

	BOOST_REQUIRE(
		field1 != field2
	);

	BOOST_REQUIRE(
		field1 < field2
	);

	std::swap(
		field1,
		field2
	);

	BOOST_REQUIRE(
		field2 < field1
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_bitfield_is_subset_eq
)
{
FCPPT_PP_POP_WARNING

	bitfield field1(
		bitfield::null()
	);

	bitfield field2(
		bitfield::null()
	);

	BOOST_REQUIRE(
		fcppt::container::bitfield::is_subset_eq(
			field1,
			field2
		)
	);

	BOOST_REQUIRE(
		fcppt::container::bitfield::is_subset_eq(
			field2,
			field1
		)
	);

	field2[test_enum::test1] = true;

	BOOST_REQUIRE(
		fcppt::container::bitfield::is_subset_eq(
			field1,
			field2
		)
	);

	field1[test_enum::test2] = true;

	BOOST_REQUIRE(
		!fcppt::container::bitfield::is_subset_eq(
			field1,
			field2
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_bitfield_empty
)
{
FCPPT_PP_POP_WARNING

	empty_bitfield field{
		fcppt::no_init()
	};

	BOOST_CHECK_EQUAL(
		empty_bitfield::static_size::value,
		0u
	);
}

namespace
{

bool
check_bit(
	bitfield::internal_type const _value,
	test_enum const _enum
)
{
	return
		(
			_value
			&
			(
				fcppt::literal<
					bitfield::internal_type
				>(
					1
				)
				<<
				static_cast<
					bitfield::internal_type
				>(
					_enum
				)
			)
		)
		!=
		fcppt::literal<
			bitfield::internal_type
		>(
			0
		);
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_bitfield_underlying_value
)
{
FCPPT_PP_POP_WARNING
	bitfield field1(
		bitfield::null()
	);

	field1[
		test_enum::test2
	] = true;

	bitfield::internal_type const value(
		fcppt::container::bitfield::underlying_value(
			field1
		)
	);

	BOOST_REQUIRE(
		!check_bit(
			value,
			test_enum::test1
		)
	);

	BOOST_REQUIRE(
		check_bit(
			value,
			test_enum::test2
		)
	);

	BOOST_REQUIRE(
		!check_bit(
			value,
			test_enum::test3
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_bitfield_initializer_list
)
{
FCPPT_PP_POP_WARNING

	bitfield const field1{
		test_enum::test1,
		test_enum::test3
	};

	BOOST_CHECK(
		field1.get(
			test_enum::test1
		)
	);

	BOOST_CHECK(
		!field1.get(
			test_enum::test2
		)
	);

	BOOST_CHECK(
		field1.get(
			test_enum::test3
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_bitfield_hash
)
{
FCPPT_PP_POP_WARNING

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

	BOOST_CHECK(
		values.count(
			bitfield{
				test_enum::test1,
				test_enum::test2
			}
		)
		==
		1u
	);

	BOOST_CHECK(
		values.count(
			bitfield{
				test_enum::test1
			}
		)
		==
		1u
	);

	BOOST_CHECK(
		values.count(
			bitfield{
				test_enum::test2
			}
		)
		==
		0u
	);
}
