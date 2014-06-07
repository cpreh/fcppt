//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/mpl/all_of.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	mpl_all_of
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK((
		fcppt::mpl::all_of<
			boost::mpl::vector2<
				int,
				long
			>,
			std::is_integral<
				boost::mpl::_1
			>
		>::value
	));

	BOOST_CHECK((
		!fcppt::mpl::all_of<
			boost::mpl::vector2<
				float,
				int
			>,
			std::is_integral<
				boost::mpl::_1
			>
		>::value
	));
}
