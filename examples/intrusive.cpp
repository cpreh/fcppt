//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/reference_impl.hpp>
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

using
element_list
=
fcppt::intrusive::list<
	element
>;
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
		fcppt::reference<
			element_list
		> const _list,
		int const _value
	)
	:
		fcppt::intrusive::base<
			element
		>{
			_list.get()
		},
		value_{
			_value
		}
	{
	}

	element(
		element &&
	)
	noexcept
	= default;

	element &
	operator=(
		element &&
	)
	noexcept
	= default;

	~element()
	= default;

	[[nodiscard]]
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
		fcppt::make_ref(list),
		5 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	};

	{
		element e2{
			fcppt::make_ref(list),
			10 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		};

		// Prints 5, 10
		for(
			element const &e
			:
			list
		)
		{
			std::cout << e.value() << ' ';
		}
	}

	std::cout << '\n';

	// Prints 5
	for(
		element const &e
		:
		list
	)
	{
		std::cout << e.value() << ' ';
	}

//! [intrusive_test]
	std::cout << '\n';

	element e3{
		std::move(
			e1
		)
	};

	element e4{
		fcppt::make_ref(list),
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
	{
		std::cout << e.value() << ' ';
	}
}

}

int
main()
{
	test_func();
}
