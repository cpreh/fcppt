//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::reference<
	int
>
int_ref;

typedef
fcppt::reference<
	int const
>
const_int_ref;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	reference
)
{

FCPPT_PP_POP_WARNING

	int x(
		42
	);

	int_ref ref(
		x
	);

	BOOST_CHECK_EQUAL(
		&ref.get(),
		&x
	);

	const_int_ref cref(
		x
	);

	BOOST_CHECK_EQUAL(
		&cref.get(),
		&x
	);

	BOOST_CHECK_EQUAL(
		&fcppt::make_ref(
			x
		).get(),
		&x
	);

	BOOST_CHECK_EQUAL(
		&fcppt::make_cref(
			x
		).get(),
		&x
	);

	int_ref other_ref(
		ref
	);

	BOOST_CHECK_EQUAL(
		&other_ref.get(),
		&ref.get()
	);

	ref = other_ref;

	BOOST_CHECK_EQUAL(
		&other_ref.get(),
		&ref.get()
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	reference_hash
)
{

FCPPT_PP_POP_WARNING

	typedef
	std::unordered_set<
		int_ref
	>
	int_ref_set;

	int x(
		42
	);

	int_ref_set set;

	set.insert(
		int_ref(
			x
		)
	);

	{
		int_ref_set::const_iterator const it(
			set.find(
				int_ref(
					x
				)
			)
		);

		BOOST_REQUIRE(
			it
			!=
			set.end()
		);

		BOOST_CHECK_EQUAL(
			&it->get(),
			&x
		);
	}

	typedef
	std::unordered_set<
		const_int_ref
	>
	const_int_ref_set;

	int const y(
		42
	);

	const_int_ref_set const_set;

	const_set.insert(
		const_int_ref(
			y
		)
	);

	{
		const_int_ref_set::const_iterator const it(
			const_set.find(
				const_int_ref(
					y
				)
			)
		);

		BOOST_REQUIRE(
			it
			!=
			const_set.end()
		);

		BOOST_CHECK_EQUAL(
			&it->get(),
			&y
		);
	}
}
