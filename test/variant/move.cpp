//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/variant/get_exn.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"variant move",
	"[variant]"
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::variant::object<
		int_unique_ptr,
		std::string
	>
	variant;

	variant test(
		fcppt::make_unique_ptr<
			int
		>(
			42
		)
	);

	CHECK(
		*fcppt::variant::get_exn<
			int_unique_ptr
		>(
			test
		)
		==
		42
	);

	variant test2(
		std::move(
			test
		)
	);

	CHECK(
		*fcppt::variant::get_exn<
			int_unique_ptr
		>(
			test2
		)
		==
		42
	);

	variant test3(
		std::string(
			"test"
		)
	);

	variant test4(
		std::string(
			"test2"
		)
	);

	test4 =
		std::move(
			test3
		);

	CHECK(
		fcppt::variant::get_exn<
			std::string
		>(
			test4
		)
		==
		std::string(
			"test"
		)
	);

	test4 =
		std::move(
			test2
		);

	CHECK(
		*fcppt::variant::get_exn<
			int_unique_ptr
		>(
			test4
		)
		==
		42
	);
}

TEST_CASE(
	"variant move nested",
	"[variant]"
)
{
	typedef
	fcppt::variant::object<
		fcppt::unique_ptr<
			int
		>
	>
	variant_unique_ptr;

	typedef
	fcppt::variant::object<
		variant_unique_ptr
	>
	nested;

	nested test{
		variant_unique_ptr{
			fcppt::make_unique_ptr<
				int
			>(
				42
			)
		}
	};

	CHECK(
		*fcppt::variant::get_exn<
			fcppt::unique_ptr<
				int
			>
		>(
			fcppt::variant::get_exn<
				variant_unique_ptr
			>(
				test
			)
		)
		==
		42
	);

	nested test2{
		variant_unique_ptr{
			fcppt::make_unique_ptr<
				int
			>(
				10
			)
		}
	};

	test2 =
		std::move(
			test
		);

	CHECK(
		*fcppt::variant::get_exn<
			fcppt::unique_ptr<
				int
			>
		>(
			fcppt::variant::get_exn<
				variant_unique_ptr
			>(
				test2
			)
		)
		==
		42
	);
}
