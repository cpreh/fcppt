//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/from_optional.hpp>
#include <fcppt/optional_bind.hpp>
#include <fcppt/optional_bind_construct.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{

void
optional_example()
{
//! [optional_example]
	typedef fcppt::optional<
		unsigned
	> optional_uint;

	auto const test_function(
		[](
			optional_uint opt
		)
		{
			// Test if opt is set
			if(
				opt.has_value()
			)
				// Output the value
				// This is undefined if has_value() == false
				std::cout << *opt << '\n';
		}
	);

	// Prints nothing
	test_function(
		optional_uint()
	);

	// Prints 3
	test_function(
		optional_uint(3u)
	);
//! [optional_example]
}

void
optional_copy()
{
//! [optional_copy]
	typedef fcppt::optional<
		unsigned
	> optional_uint;

	unsigned int1{
		5u
	};

	// opt takes a copy of int1
	optional_uint opt{
		int1
	};

	int1 = 10u;

	// The value of opt will still be 5u
	std::cout << (*opt != int1) << '\n';
//! [optional_copy]
}

void
optional_bind()
{
//! [optional_bind]
	typedef fcppt::optional<
		unsigned
	> optional_uint;

	typedef fcppt::optional<
		std::string
	> optional_string;

	optional_string const value{
		fcppt::optional_bind(
			optional_uint{3u},
			[](
				unsigned const _val
			)
			{
				return
					optional_string(
						std::to_string(
							_val
						)
					);
			}
		)
	};

	std::cout << (*value == "3") << '\n';
//! [optional_bind]

//! [optional_bind_construct]
	optional_string const value2{
		fcppt::optional_bind_construct(
			optional_uint{3u},
			[](
				unsigned const _val
			)
			{
				return
					std::to_string(
						_val
					);
			}
		)
	};

	std::cout << (*value == "3") << '\n';
//! [optional_bind_construct]
}

void
from_optional()
{
//! [from_optional]
	typedef fcppt::optional<
		unsigned
	> optional_uint;

	unsigned const value{
		fcppt::from_optional(
			optional_uint(),
			[]{
				return
					42u;
			}
		)
	};

	std::cout << (value == 42u) << '\n';
//! [from_optional]
}

}

int
main()
{
	optional_example();

	optional_copy();

	optional_bind();

	from_optional();
}
