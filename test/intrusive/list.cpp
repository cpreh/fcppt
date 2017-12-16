//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/intrusive/base.hpp>
#include <fcppt/intrusive/list.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

class test_class;

typedef
fcppt::intrusive::list<
	test_class
>
test_list;

class test_class
:
	public fcppt::intrusive::base
{
	FCPPT_NONCOPYABLE(
		test_class
	);
public:
	test_class(
		test_list &_list,
		int const _value
	)
	:
		fcppt::intrusive::base{
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
	=
	default;

	test_class &
	operator=(
		test_class &&
	)
	=
	default;

	~test_class()
	{
	}

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

BOOST_AUTO_TEST_CASE(
	list
)
{
	test_list my_list{};

	BOOST_CHECK_EQUAL(
		std::distance(
			my_list.begin(),
			my_list.end()
		),
		0
	);

	test_class test1{
		my_list,
		42
	};

	BOOST_CHECK_EQUAL(
		std::distance(
			my_list.begin(),
			my_list.end()
		),
		1
	);

	BOOST_CHECK(
		std::next(
			my_list.begin()
		)
		==
		my_list.end()
	);

	{
		test_class test2{
			my_list,
			10
		};

		BOOST_CHECK(
			std::next(
				std::next(
					my_list.begin()
				)
			)
			==
			my_list.end()
		);

		BOOST_CHECK_EQUAL(
			std::distance(
				my_list.begin(),
				my_list.end()
			),
			2
		);

		BOOST_CHECK_EQUAL(
			my_list.begin()->value(),
			42
		);

		BOOST_CHECK_EQUAL(
			std::next(
				my_list.begin()
			)->value(),
			10
		);

		test_class test3{
			std::move(
				test2
			)
		};

		BOOST_CHECK_EQUAL(
			std::distance(
				my_list.begin(),
				my_list.end()
			),
			2
		);
	}

	BOOST_CHECK(
		std::next(
			my_list.begin()
		)
		==
		my_list.end()
	);
}
