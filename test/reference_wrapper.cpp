//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_wrapper.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	reference_wrapper
)
{

FCPPT_PP_POP_WARNING

	typedef fcppt::reference_wrapper<
		int
	> int_ref;

	typedef fcppt::reference_wrapper<
		int const
	> const_int_ref;

	int x(
		42
	);

	int_ref ref(
		x
	);

	BOOST_CHECK(
		&ref.get()
		==
		&x
	);

	const_int_ref cref(
		x
	);

	BOOST_CHECK(
		&cref.get()
		==
		&x
	);

	BOOST_CHECK(
		&fcppt::make_ref(
			x
		).get()
		==
		&x
	);

	BOOST_CHECK(
		&fcppt::make_cref(
			x
		).get()
		==
		&x
	);

	int_ref other_ref(
		ref
	);

	BOOST_CHECK(
		&other_ref.get()
		==
		&ref.get()
	);

	ref = other_ref;

	BOOST_CHECK(
		&other_ref.get()
		==
		&ref.get()
	);
}
