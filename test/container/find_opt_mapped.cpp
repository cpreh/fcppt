//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/reference_wrapper_comparison.hpp>
#include <fcppt/reference_wrapper_impl.hpp>
#include <fcppt/reference_wrapper_output.hpp>
#include <fcppt/container/find_opt_mapped.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <map>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_find_exn
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::map<
		int,
		std::string
	>
	int_string_map;

	int_string_map const values{
		std::make_pair(
			42,
			std::string(
				"test"
			)
		),
		std::make_pair(
			100,
			std::string(
				"test2"
			)
		)
	};

	typedef
	fcppt::optional::object<
		fcppt::reference_wrapper<
			std::string const
		>
	>
	optional_string;

	BOOST_CHECK_EQUAL(
		optional_string(
			fcppt::container::find_opt_mapped(
				values,
				42
			)
		),
		optional_string(
			fcppt::make_cref(
				values.at(
					42
				)
			)
		)
	);

	BOOST_CHECK(
		!fcppt::container::find_opt_mapped(
			values,
			50
		).has_value()
	);
}
