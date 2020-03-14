//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/cast/bad_truncation_check.hpp>
#include <fcppt/cast/truncation_check.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>

namespace
{

//! [truncation_check_cast_int_long]
void
check_int_long()
try
{
	// Try to cast the greatest unsigned long value into an unsigned int.
	// This might fail or it might not fail depending on the
	// implementation.
	// fcppt::bad_truncation_check_cast will be thrown on failure.
	auto const result(
		fcppt::cast::truncation_check<
			unsigned
		>(
			std::numeric_limits<
				unsigned long //NOLINT(google-runtime-int)
			>::max()
		)
	);

	fcppt::io::cout()
		<< FCPPT_TEXT("The casted value is ")
		<< result
		<< FCPPT_TEXT('\n');
}
catch(
	fcppt::cast::bad_truncation_check const &_error
)
{
	fcppt::io::cout()
		<< _error.string()
		<< FCPPT_TEXT('\n');
}
//! [truncation_check_cast_int_long]


//! [truncation_check_cast_negative]
void
negative_conversion()
try
{
	// -1 cannot be represented as an unsigned. This will throw an
	// fcppt::bad_truncation_check_cast.
	auto const result(
		fcppt::cast::truncation_check<
			unsigned
		>(
			-1
		)
	);

	fcppt::io::cout()
		<< FCPPT_TEXT("The casted value is ")
		<< result
		<< FCPPT_TEXT('\n');
}
catch(
	fcppt::cast::bad_truncation_check const &_error
)
{
	fcppt::io::cout()
		<< _error.string()
		<< FCPPT_TEXT('\n');
}
//! [truncation_check_cast_negative]

}

int
main()
{
	check_int_long();

	negative_conversion();
}
//]
