//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/intrusive/base.hpp>
#include <fcppt/intrusive/list.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

//! [intrusive_fwd]
class element;

typedef
fcppt::intrusive::list<
	element
>
element_list;
//! [intrusive_fwd]

//! [intrusive_element]
class element
:
	public
	fcppt::intrusive::base<
		element
	>
{
	FCPPT_NONCOPYABLE(
		element
	);
public:
	element(
		element_list &_list,
		int const _value
	)
	:
		fcppt::intrusive::base<
			element
		>{
			_list
		},
		value_{
			_value
		}
	{
	}

	element(
		element &&
	) = default;

	element &
	operator=(
		element &&
	) = default;

	~element()
	{
	}

	int
	value() const
	{
		return value_;
	}
private:
	int value_;
};
//! [intrusive_element]

void
test_func()
{
//! [intrusive_test]
	element_list list{};

	element e1{
		list,
		5
	};

	{
		element e2{
			list,
			10
		};

		// Prints 5, 10
		for(
			element const &e
			:
			list
		)
			std::cout << e.value() << ' ';
	}

	std::cout << '\n';

	// Prints 5
	for(
		element const &e
		:
		list
	)
		std::cout << e.value() << ' ';

//! [intrusive_test]
	std::cout << '\n';

	element e3{
		std::move(
			e1
		)
	};

	element e4{
		list,
		1
	};

	e4 =
		std::move(
			e3
		);

	for(
		element const &e
		:
		list
	)
		std::cout << e.value() << ' ';
}

}

int
main()
{
	test_func();
}
