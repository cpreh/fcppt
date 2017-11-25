//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/error.hpp>
#include <fcppt/either/fold_error.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	either_fold_error
)
{
	typedef
	fcppt::either::error<
		std::string
	>
	either_error;

	{
		either_error const result{
			fcppt::either::fold_error(
				std::vector<
					int
				>{
					1,2,3
				},
				[](
					int const _value
				)
				{
					return
						_value % 2
						==
						0
						?
							either_error{
								std::string{"test"}
							}
						:
							either_error{
								fcppt::either::no_error{}
							}
						;
				}
			)
		};

		BOOST_CHECK_EQUAL(
			result,
			either_error{
				std::string{
					"test"
				}
			}
		);
	}

	{
		either_error const result{
			fcppt::either::fold_error(
				fcppt::assign::make_container<
					std::vector<
						fcppt::unique_ptr<
							int
						>
					>
				>(
					fcppt::make_unique_ptr<
						int
					>(
						2
					),
					fcppt::make_unique_ptr<
						int
					>(
						4
					)
				),
				[](
					fcppt::unique_ptr<
						int
					> &&_value
				)
				{
					return
						*_value % 2
						==
						0
						?
							either_error{
								fcppt::either::no_error{}
							}
						:
							either_error{
								std::string{"test"}
							}
						;
				}
			)
		};

		BOOST_CHECK_EQUAL(
			result,
			either_error{
				fcppt::either::no_error{}
			}
		);
	}
}
