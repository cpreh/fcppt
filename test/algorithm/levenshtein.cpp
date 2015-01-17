//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/levenshtein.hpp>
#include <fcppt/algorithm/shortest_levenshtein.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>

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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_levenshtein
)
{
FCPPT_PP_POP_WARNING

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


