//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/error.hpp>
#include <fcppt/either/fold_error.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::fold_error",
	"[either]"
)
{
	typedef
	fcppt::either::error<
		std::string
	>
	either_error;

	CHECK(
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
		==
		either_error{
			std::string{
				"test"
			}
		}
	);

	CHECK(
		fcppt::either::fold_error(
			fcppt::container::make<
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
		==
		either_error{
			fcppt::either::no_error{}
		}
	);
}
