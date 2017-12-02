//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/int_iterator_impl.hpp>
#include <fcppt/int_range_impl.hpp>
#include <fcppt/make_int_range.hpp>
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/make_literal_strong_typedef.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/type_iso/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <iterator>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

template<
	typename Iterator
>
void
check_category(
	Iterator
)
{
	static_assert(
		std::is_same<
			typename
			Iterator::iterator_category,
			std::input_iterator_tag
		>::value,
		""
	);
}

static_assert(
	std::is_same<
		fcppt::int_iterator<
			int
		>::iterator_category,
		std::input_iterator_tag
	>::value,
	""
);

template<
	typename Int
>
void
test(
	fcppt::int_range<
		Int
	> const _range,
	std::vector<
		Int
	> const &_result
)
{
	check_category(
		_range.begin()
	);

	typedef
	std::vector<
		Int
	>
	int_vector;

	int_vector values;

	for(
		Int const value
		:
		_range
	)
		values.push_back(
			value
		);

	BOOST_CHECK_EQUAL(
		static_cast<
			typename
			int_vector::size_type
		>(
			_range.size()
		),
		values.size()
	);

	BOOST_CHECK((
		values
		==
		_result
	));
}

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	strong_int
);

}

BOOST_AUTO_TEST_CASE(
	int_range
)
{
	test(
		fcppt::make_int_range(
			0,
			3
		),
		std::vector<
			int
		>{
			0,
			1,
			2
		}
	);
}

BOOST_AUTO_TEST_CASE(
	int_range_count
)
{
	test(
		fcppt::make_int_range_count(
			2
		),
		std::vector<
			int
		>{
			0,
			1
		}
	);
}

BOOST_AUTO_TEST_CASE(
	int_range_count_strong_typedef
)
{
	test(
		fcppt::make_int_range_count(
			strong_int(
				2
			)
		),
		std::vector<
			strong_int
		>{
			strong_int(
				0
			),
			strong_int(
				1
			)
		}
	);
}

BOOST_AUTO_TEST_CASE(
	int_range_empty
)
{
	test(
		fcppt::make_int_range(
			3,
			2
		),
		std::vector<
			int
		>{}
	);
}
