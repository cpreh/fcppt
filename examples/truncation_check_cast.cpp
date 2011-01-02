//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[truncation_check_cast
#include <fcppt/truncation_check_cast.hpp>
#include <fcppt/bad_truncation_check_cast.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <limits>

int main()
try
{
	// try to cast the greatest unsigned long value into an unsigned int
	// this might fail or it might not fail depending on the implementation
	unsigned const result(
		fcppt::truncation_check_cast<
			unsigned
		>(
			std::numeric_limits<
				unsigned long
			>::max()
		)
	);

	fcppt::io::cout
		<< FCPPT_TEXT("The casted value is ")
		<< result
		<< FCPPT_TEXT('\n');
}
catch(
	fcppt::bad_truncation_check_cast const &e
)
{
	fcppt::io::cout
		<< e.string()
		<< FCPPT_TEXT('\n');
}
//]
