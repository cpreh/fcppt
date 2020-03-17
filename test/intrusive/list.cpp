//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/intrusive/base.hpp>
#include <fcppt/intrusive/list.hpp>
#include <fcppt/range/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

class test_class;

using
test_list
=
fcppt::intrusive::list<
	test_class
>;

class test_class
:
	public
		fcppt::intrusive::base<
			test_class
		>
{
	FCPPT_NONCOPYABLE(
		test_class
	);
public:
	test_class(
		test_list &_list, //NOLINT(google-runtime-references)
		int const _value
	)
	:
		fcppt::intrusive::base<
			test_class
		>{
			_list
		},
		value_{
			_value
		}
	{
	}

	test_class(
		test_class &&
	)
	noexcept
	=
	default;

	test_class &
	operator=(
		test_class &&
	)
	noexcept
	=
	default;

	~test_class()
	= default;

	[[nodiscard]]
	int
	value() const
	{
		return
			value_;
	}
private:
	int value_;
};

}

TEST_CASE(
	"intrusive::list"
	"[intrusive]"
)
{
	test_list my_list{};

	CHECK(
		std::distance(
			my_list.begin(),
			my_list.end()
		)
		==
		0
	);

	{
		test_class test1{
			my_list,
			42 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		};

		CHECK(
			std::distance(
				my_list.begin(),
				my_list.end()
			)
			==
			1
		);

		CHECK(
			std::next( // NOLINT(fuchsia-default-arguments-calls)
				my_list.begin()
			)
			==
			my_list.end()
		);

		{
			test_class test2{
				my_list,
				10 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			};

			CHECK(
				std::next( // NOLINT(fuchsia-default-arguments-calls)
					my_list.begin(),
					2
				)
				==
				my_list.end()
			);

			CHECK(
				std::distance(
					my_list.begin(),
					my_list.end()
				)
				==
				2
			);

			CHECK(
				my_list.begin()->value()
				==
				42 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			);

			CHECK(
				std::next( // NOLINT(fuchsia-default-arguments-calls)
					my_list.begin()
				)->value()
				==
				10 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			);

			test_class test3{
				std::move(
					test2
				)
			};

			CHECK(
				std::distance(
					my_list.begin(),
					my_list.end()
				)
				==
				2
			);
		}

		CHECK(
			std::next( // NOLINT(fuchsia-default-arguments-calls)
				my_list.begin()
			)
			==
			my_list.end()
		);

		test_list my_list2{
			std::move(
				my_list
			)
		};

		CHECK(
			std::next( // NOLINT(fuchsia-default-arguments-calls)
				my_list2.begin()
			)
			==
			my_list2.end()
		);
	}
}

TEST_CASE(
	"intrusive::list size"
	"[intrusive]"
)
{
	test_list my_list{};

	REQUIRE(
		fcppt::range::size(
			my_list
		)
		==
		0U
	);

	{
		test_class test1{
			my_list,
			0
		};

		REQUIRE(
			fcppt::range::size(
				my_list
			)
			==
			1U
		);

		{
			test_class test2{
				my_list,
				0
			};

			REQUIRE(
				fcppt::range::size(
					my_list
				)
				==
				2U
			);
		}

		REQUIRE(
			fcppt::range::size(
				my_list
			)
			==
			1U
		);
	}

	REQUIRE(
		fcppt::range::size(
			my_list
		)
		==
		0U
	);

	{
		test_class test1{
			my_list,
			0
		};

		REQUIRE(
			fcppt::range::size(
				my_list
			)
			==
			1U
		);

		{
			test_class test2{
				my_list,
				0
			};

			REQUIRE(
				fcppt::range::size(
					my_list
				)
				==
				2U
			);
		}

		REQUIRE(
			fcppt::range::size(
				my_list
			)
			==
			1U
		);
	}
}

TEST_CASE(
	"intrusive::list move assign"
	"[intrusive]"
)
{
	test_list list{};

	// list.prev = list
	// list.next = list

	{
		test_class e3{
			list,
			1
		};

		// e3.prev := list.prev = list
		// e3.next := list
		// list.prev.next = list.next := e3
		// list.prev := e3

		test_class e4{
			list,
			2
		};

		// e4.prev := list.prev = e3
		// e4.next := list
		// list.prev.next = e3.next := e4
		// list.prev = e4

		// list.next = e3
		// list.prev = e4
		// e3.prev = list
		// e3.next = e4
		// e4.prev = e3
		// e4.next = list

		e4 =
			std::move(
				e3
			);

		// e4.next.prev = list.prev := e4.prev = e3
		// e4.prev.next = e3.next := e4.next = list
		// e4.prev := e3.prev = list
		// e4.next := e3.next = list
		// e4.prev.next = list.next := e4
		// e4.next.prev = list.prev := e4
		// e3.next = e3
		// e3.prev = e3

		// list.next = e4
		// list.prev = e4
		// e4.prev = list
		// e4.next = list
	}

	CHECK(
		list.empty()
	);
}
