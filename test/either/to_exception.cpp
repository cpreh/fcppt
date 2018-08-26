//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::to_exception",
	"[either]"
)
{
	typedef
	fcppt::either::object<
		fcppt::string,
		int
	>
	either_int;

	auto const make_exception(
		[](
			fcppt::string const &_error
		){
			return
				fcppt::exception(
					fcppt::string(
						_error
					)
				);
		}
	);

	CHECK(
		fcppt::either::to_exception(
			either_int{
				3
			},
			make_exception
		)
		==
		3
	);

	CHECK_THROWS_MATCHES(
		fcppt::either::to_exception(
			either_int{
				fcppt::string(
					FCPPT_TEXT("Invalid")
				)
			},
			make_exception
		),
		fcppt::exception,
		Catch::Matchers::Predicate<
			fcppt::exception
		>(
			[](
				fcppt::exception const &_exn
			)
			{
				return
					_exn.string()
					==
					FCPPT_TEXT("Invalid");
			}
		)
	);
}
