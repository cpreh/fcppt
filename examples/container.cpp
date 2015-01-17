//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


int main()
try
{
	typedef fcppt::container::raw_vector<
		char
	> vector_type;

	std::string const test_string(
		"abcdefg"
	);

	vector_type vec;

	vec.reserve(42);

	vec.insert(
		vec.end(),
		test_string.begin(),
		test_string.end()
	);

	FCPPT_ASSERT_ERROR(
		vec.size() == test_string.size()
	);

	vec.insert(
		vec.begin() + test_string.size() / 2,
		test_string.begin(),
		test_string.end()
	);

	fcppt::io::cout()
		<< vec.size()
		<< FCPPT_TEXT('\n');
}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr()
		<< _error.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
