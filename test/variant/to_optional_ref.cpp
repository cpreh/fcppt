//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/to_optional_ref.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variant_to_optional_ref
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::variant::variadic<
		int,
		std::string
	>
	variant;

	{
		variant var(
			42
		);

		BOOST_CHECK_EQUAL(
			fcppt::variant::to_optional_ref<
				int
			>(
				var
			),
			fcppt::optional::reference<
				int
			>(
				fcppt::make_ref(
					var.get_unsafe<
						int
					>()
				)
			)
		);

		BOOST_CHECK_EQUAL(
			fcppt::variant::to_optional_ref<
				std::string
			>(
				var
			),
			fcppt::optional::reference<
				std::string
			>()
		);
	}

	{
		variant const var(
			42
		);

		BOOST_CHECK_EQUAL(
			fcppt::variant::to_optional_ref<
				int const
			>(
				var
			),
			fcppt::optional::reference<
				int const
			>(
				fcppt::make_cref(
					var.get_unsafe<
						int
					>()
				)
			)
		);

		BOOST_CHECK_EQUAL(
			fcppt::variant::to_optional_ref<
				std::string const
			>(
				var
			),
			fcppt::optional::reference<
				std::string const
			>()
		);
	}
}
