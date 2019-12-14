//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/get_exn.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"variant::get",
	"[variant]"
)
{
	typedef
	fcppt::variant::object<
		bool,
		int,
		std::string
	>
	variant;

	std::string const string(
		"hello world"
	);

	variant test(
		string
	);

	CHECK(
		fcppt::variant::get_exn<
			std::string
		>(
			test
		)
		==
		string
	);
}
