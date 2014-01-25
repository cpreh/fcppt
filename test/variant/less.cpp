//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/less.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variant_less
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::variant::object<
		boost::mpl::vector2<
			int,
			std::string
		>
	> variant;

	variant const v1(
		10
	);

	variant const v2(
		20
	);

	BOOST_CHECK(
		v1 < v2
	);

	BOOST_CHECK(
		!(v2 < v1)
	);

	variant const v3(
		std::string(
			"hello world"
		)
	);

	BOOST_CHECK(
		v1 < v3
	);

	BOOST_CHECK(
		!(v3 < v1)
	);
}
