//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/exception.hpp>
#include <fcppt/assert/information.hpp>
#include <fcppt/assert/make_message.hpp>
#include <fcppt/assert/post_message.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/assert/throw.hpp>
#include <fcppt/assert/unreachable.hpp>
#include <fcppt/io/cerr.hpp>


namespace
{

bool
other_function();

bool
other_function()
{
	return false;
}

//! [assert_pre_post]
void
library_function(
	int const _parameter
)
{
	// Assert a precondition without a message
	FCPPT_ASSERT_PRE(
		_parameter < 10
	);

	bool const some_value(
		other_function()
	);

	// Assert a postcondition with a message
	FCPPT_ASSERT_POST_MESSAGE(
		some_value,
		fcppt::assert_::exception,
		FCPPT_TEXT("other_function failed")
	);
}
// ![assert_pre_post]

// ![assert_unreachable]
enum class food
{
	apple,
	banana,
	potato,
	bread
};

// Check if a given kind of food is a fruit
bool
is_fruit(
	food const _value
)
{
	// Handle every possible enumerator
	switch(
		_value
	)
	{
	case food::apple:
	case food::banana:
		return true;
	case food::potato:
	case food::bread:
		return false;
	}

	// This should never be reached
	FCPPT_ASSERT_UNREACHABLE;
}
// ![assert_unreachable]

// ![assert_throw]
// Define an exception that can be constructed from an
// fcppt::assert_::information
class my_exception
{
public:
	explicit
	my_exception(
		fcppt::assert_::information const &_info
	)
	:
		info_(
			_info
		)
	{
	}

	fcppt::assert_::information const &
	info() const
	{
		return info_;
	}
private:
	fcppt::assert_::information info_;
};

void
throwing_function()
{
	// Throw an object of my_exception if other_function returns false
	FCPPT_ASSERT_THROW(
		other_function(),
		my_exception
	);
}

void
test_function()
try
{
	throwing_function();
}
catch(
	my_exception const &_exception
)
{
	// fcppt::assert_::make_message can be used to turn an
	// fcppt::assert_::information into a string.
	fcppt::io::cerr()
		<<
		fcppt::assert_::make_message(
			_exception.info()
		)
		<< FCPPT_TEXT('\n');
}
// ![assert_throw]

}

int
main()
try
{
	library_function(
		5
	);

	is_fruit(
		food::apple
	);

	test_function();
}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr()
		<< _error.string()
		<< FCPPT_TEXT('\n');
}
