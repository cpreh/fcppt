//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/optional/to_pointer.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_to_pointer
)
{
FCPPT_PP_POP_WARNING

	int const val{
		42
	};

	typedef
	fcppt::optional::reference<
		int const
	>
	optional_int_cref;

	BOOST_CHECK(
		fcppt::optional::to_pointer(
			optional_int_cref{}
		)
		==
		nullptr
	);

	BOOST_CHECK(
		fcppt::optional::to_pointer(
			optional_int_cref{
				fcppt::make_cref(
					val
				)
			}
		)
		==
		&val
	);
}
