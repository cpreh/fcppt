//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/copy.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"copy",
	"[various]"
)
{
	std::string const value{
		"test"
	};

	auto const function(
		[](
			std::string &&_value
		)
		->
		std::string
		{
			return
				std::move(
					_value
				);
		}
	);

	CHECK(
		function(
			fcppt::copy(
				value
			)
		)
		==
		value
	);
}
