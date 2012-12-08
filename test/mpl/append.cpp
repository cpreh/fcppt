//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/mpl/append.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	mpl_append
)
{
FCPPT_PP_POP_WARNING

	typedef boost::mpl::vector2<
		int,
		float
	> vec1;

	typedef boost::mpl::vector2<
		double,
		bool
	> vec2;

	typedef fcppt::mpl::append<
		vec1,
		vec2
	>::type appended;

	BOOST_REQUIRE((
		std::is_same<
			boost::mpl::at_c<
				appended,
				0
			>::type,
			int
		>::value
	));

	BOOST_REQUIRE((
		std::is_same<
			boost::mpl::at_c<
				appended,
				1
			>::type,
			float
		>::value
	));

	BOOST_REQUIRE((
		std::is_same<
			boost::mpl::at_c<
				appended,
				2
			>::type,
			double
		>::value
	));

	BOOST_REQUIRE((
		std::is_same<
			boost::mpl::at_c<
				appended,
				3
			>::type,
			bool
		>::value
	));
}
