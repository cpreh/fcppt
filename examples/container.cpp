//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/container/map_impl.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <map>
#include <fcppt/config/external_end.hpp>


int main()
try
{
	typedef fcppt::container::map<
		std::map<
			int,
			fcppt::string
		>
	> map_type;

	map_type map;

	map.insert(
		42,
		FCPPT_TEXT("peter")
	);

	map.insert(
		42,
		FCPPT_TEXT("peter")
	);

	for(
		map_type::const_iterator it(
			map.begin()
		);
		it != map.end();
		++it
	)
		fcppt::io::cout()
			<< it->first
			<< FCPPT_TEXT(": ")
			<< it->second
			<< FCPPT_TEXT('\n');

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
