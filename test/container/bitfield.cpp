//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/bitfield/is_subset_eq.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace
{

namespace test_enum
{

enum type
{
	test1,
	test2,
	test3,
	size
};

}

typedef fcppt::container::bitfield::object<
	test_enum::type,
	test_enum::size
> bitfield;

namespace empty_enum
{

enum type
{
	size
};

}

}

typedef fcppt::container::bitfield::object<
	empty_enum::type,
	empty_enum::size
> empty_bitfield;

#define FCPPT_INSTANTIATE_BITFIELD(\
	enum_,\
	internal_\
)\
template class fcppt::container::bitfield::object< \
	enum_::type, \
	enum_::size \
>; \
\
template class fcppt::container::bitfield::proxy< \
	fcppt::container::bitfield::array< \
		enum_::type, \
		enum_::size, \
		internal_\
	>::type & \
>; \
\
template class fcppt::container::bitfield::iterator< \
	fcppt::container::bitfield::array< \
		enum_::type, \
		enum_::size, \
		internal_ \
	>::type &, \
	fcppt::container::bitfield::proxy< \
		fcppt::container::bitfield::array< \
			enum_::type, \
			enum_::size, \
			internal_ \
		>::type & \
	> \
>;

FCPPT_INSTANTIATE_BITFIELD(
	test_enum,
	fcppt::container::bitfield::default_internal_type
)

FCPPT_INSTANTIATE_BITFIELD(
	empty_enum,
	fcppt::container::bitfield::default_internal_type
)

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

	BOOST_REQUIRE(
		!field1
	);

	field1[test_enum::test1] = true;

	BOOST_REQUIRE(
		field1
	);

	bitfield field2(
		bitfield::null()
	);

	BOOST_REQUIRE(
		(field2 | test_enum::test2)
		& test_enum::test2
	);

	BOOST_REQUIRE(
		!field2
	);

	field2[test_enum::test3] = true;

	{
		bitfield const bf_or(
			field1 | field2
		);

		BOOST_REQUIRE(
			bf_or[test_enum::test1]
			&& !bf_or[test_enum::test2]
			&& bf_or[test_enum::test3]
		);
	}

	BOOST_REQUIRE(
		!(field1 & field2)
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

	bitfield::iterator it(
		field1.begin()
	);

	bitfield::iterator it2;

	it = it2;

	BOOST_REQUIRE(
		it == it2
	);
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

	empty_bitfield field;

	BOOST_REQUIRE(
		field.size() == 0u
	);

	BOOST_REQUIRE(
		field.begin()
		== field.end()
	);
}
