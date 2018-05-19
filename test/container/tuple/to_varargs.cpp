//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/container/tuple/to_varargs.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <string>
#include <tuple>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::tuple::to_varargs",
	"[container],[tuple]"
)
{
	std::tuple<
		int,
		std::string
	> const tuple1{
		42,
		"42"
	};

	fcppt::container::tuple::to_varargs(
		tuple1,
		[](
			int const _val,
			std::string const &_string
		)
		{
			CHECK(
				_val
				==
				42
			);

			CHECK(
				_string
				==
				std::string{
					"42"
				}
			);
		}
	);

	fcppt::container::tuple::to_varargs(
		std::make_tuple(
			fcppt::make_unique_ptr<
				int
			>(
				100
			)
		),
		[](
			fcppt::unique_ptr<
				int
			> &&_ptr
		)
		{
			CHECK(
				*_ptr
				==
				100
			);
		}
	);
}
