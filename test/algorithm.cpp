//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/levenshtein.hpp>
#include <fcppt/algorithm/remove.hpp>
#include <fcppt/algorithm/shift_compare.hpp>
#include <fcppt/algorithm/shortest_levenshtein.hpp>
#include <fcppt/math/vector/vector.hpp>
#include <boost/test/unit_test.hpp>
#include <functional>
#include <iostream>
#include <ostream>
#include <vector>

namespace
{
typedef
fcppt::math::vector::static_<int,3>::type
vector;
}

BOOST_AUTO_TEST_CASE(shift_compare)
{
	vector const first(1,2,3),second(3,1,2),third(3,2,1);

	BOOST_CHECK(
		fcppt::algorithm::shift_compare(
			first,
			second,
			std::equal_to<int>()) &&
		!fcppt::algorithm::shift_compare(
			first,
			third,
			std::equal_to<int>()));
}

namespace
{
void
test_single_levenshtein(
	std::string const &a,
	std::string const &b,
	std::string::size_type const expected)
{
	std::cout 
		<< "Expecting levenshtein distance (\"" 
		<< a 
		<< "\",\"" 
		<< b << "\") to be " 
		<< expected
		<< ", got " 
		<< 
			fcppt::algorithm::levenshtein(
				a,
				b) 
		<< "...\n";

	BOOST_CHECK(
		fcppt::algorithm::levenshtein(
			a,b) == expected);
}
}

BOOST_AUTO_TEST_CASE(leven)
{
	std::cout << "Checking levenshtein distance functions...\n";

	std::vector<std::string> strings;
	strings.push_back("foo");
	strings.push_back("barz");
	strings.push_back("baz");

	std::string const ref = "ba";

	test_single_levenshtein(
		ref,
		strings[0],
		3);

	test_single_levenshtein(
		ref,
		strings[1],
		2);

	test_single_levenshtein(
		ref,
		strings[2],
		1);

	BOOST_CHECK(
		fcppt::algorithm::shortest_levenshtein(
			strings,
			ref) == strings[2]);
}

BOOST_AUTO_TEST_CASE(algorithm_remove)
{
	typedef std::vector<
		int
	> int_vector;

	int_vector vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	BOOST_REQUIRE(
		fcppt::algorithm::remove(
			vec,
			2
		)
	);

	BOOST_REQUIRE(
		vec.size() == 2u
		&& vec[0] == 1
		&& vec[1] == 3
	);
}
