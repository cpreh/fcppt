//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/map_impl.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert.hpp>
#include <fcppt/exception.hpp>
#include <boost/foreach.hpp>
#include <map>
#include <cstdlib>

int main()
try
{
	typedef fcppt::container::map<
		std::map<
			int,
			fcppt::string
		>
	> map_type;

	map_type m;

	m.insert(
		42,
		FCPPT_TEXT("peter")
	);

	m.insert(
		42,
		FCPPT_TEXT("peter")
	);
	BOOST_FOREACH(
		map_type::const_reference r,
		m
	)
		fcppt::io::cout
			<< r.first
			<< FCPPT_TEXT(": ")
			<< r.second
			<< '\n';

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

	FCPPT_ASSERT(
		vec.size() == test_string.size()
	);

	vec.insert(
		vec.begin() + test_string.size() / 2,
		test_string.begin(),
		test_string.end()
	);

	fcppt::io::cout << vec.size() << '\n';
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr
		<< e.string()
		<< FCPPT_TEXT('\n');
	
	return EXIT_FAILURE;
}
