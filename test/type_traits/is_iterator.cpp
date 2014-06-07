//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/is_bidirectional_iterator.hpp>
#include <fcppt/type_traits/is_forward_iterator.hpp>
#include <fcppt/type_traits/is_input_iterator.hpp>
#include <fcppt/type_traits/is_iterator.hpp>
#include <fcppt/type_traits/is_output_iterator.hpp>
#include <fcppt/type_traits/is_random_access_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <iterator>
#include <list>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace
{

struct not_iterator
{};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	type_traits_is_iterator
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		fcppt::type_traits::is_iterator<
			int *
		>::value
	);

	BOOST_CHECK(
		fcppt::type_traits::is_iterator<
			int const *
		>::value
	);

	BOOST_CHECK(
		fcppt::type_traits::is_iterator<
			std::string::iterator
		>::value
	);

	BOOST_CHECK(
		fcppt::type_traits::is_iterator<
			std::string::const_iterator
		>::value
	);

	BOOST_CHECK(
		!fcppt::type_traits::is_iterator<
			int
		>::value
	);

	BOOST_CHECK(
		!fcppt::type_traits::is_iterator<
			not_iterator
		>::value
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	type_traits_iterator_category
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		fcppt::type_traits::is_input_iterator<
			int *
		>::value
	);

	BOOST_CHECK(
		fcppt::type_traits::is_random_access_iterator<
			int *
		>::value
	);

	BOOST_CHECK(
		!fcppt::type_traits::is_random_access_iterator<
			std::list<int>::const_iterator
		>::value
	);

	BOOST_CHECK(
		fcppt::type_traits::is_bidirectional_iterator<
			std::list<int>::const_iterator
		>::value
	);

	BOOST_CHECK(
		fcppt::type_traits::is_forward_iterator<
			std::list<int>::const_iterator
		>::value
	);

	BOOST_CHECK(
		fcppt::type_traits::is_output_iterator<
			std::ostream_iterator<
				int
			>
		>::value
	);
}
