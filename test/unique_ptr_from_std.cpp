//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/unique_ptr_from_std.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	unique_ptr_from_std
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		fcppt::optional::maybe(
			fcppt::unique_ptr_from_std(
				std::make_unique<
					int
				>(
					42
				)
			),
			fcppt::const_(
				false
			),
			[](
				fcppt::unique_ptr<
					int
				> const &_ptr
			)
			{
				return
					*_ptr
					==
					42;
			}
		)
	);

	BOOST_CHECK(
		!fcppt::unique_ptr_from_std(
			std::unique_ptr<
				int
			>{}
		).has_value()
	);
}
