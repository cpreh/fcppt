//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/unique_ptr_from_std.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	unique_ptr_from_std
)
{
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
