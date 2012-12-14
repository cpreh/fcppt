//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/append.hpp>
#include <fcppt/algorithm/array_map.hpp>
#include <fcppt/algorithm/join_strings.hpp>
#include <fcppt/algorithm/levenshtein.hpp>
#include <fcppt/algorithm/shift_compare.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <functional>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


int
main()
{
{
//! [append]
std::vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
std::vector<int> w;
w.push_back(4);
w.push_back(5);

fcppt::algorithm::append(
	v,
	w);

// Now v contains: 1,2,3,4,5
//! [append]
}

{
//! [array_map]
typedef
std::array<int,3>
three_ints;

three_ints const a = {{ 1,2,3 }};
three_ints const b(
	fcppt::algorithm::array_map<three_ints>(
		a,
		[](int const _arg) { return _arg * 3; }));
// b now contains: 3, 6, 9
//! [array_map]
std::cout << b.empty() << '\n';
}

{
//! [join_strings]
std::vector<std::string> strings;

strings.push_back("lol");
strings.push_back("rofl");
strings.push_back("wololololooo");

std::string const result =
	fcppt::algorithm::join_strings(
		strings,
		",");

// Outputs "lol,rofl,wololololooo"
std::cout << result << "\n";
//! [join_strings]
}

{
//! [levenshtein]
std::string const a = "foobarbaz";
std::string const b = "fobarbax";

std::string::size_type const result =
	fcppt::algorithm::levenshtein(
		a,
		b);

std::cout << result << "\n";
//! [levenshtein]
}

{
//! [shift_compare]
std::vector<int> a;
a.push_back(1);
a.push_back(2);
a.push_back(3);
std::vector<int> b;
b.push_back(3);
b.push_back(1);
b.push_back(2);
std::vector<int> c;
c.push_back(1);
c.push_back(3);
c.push_back(2);

bool const first_result =
	fcppt::algorithm::shift_compare(
		a,
		b,
		::std::equal_to<int>());

bool const second_result =
	fcppt::algorithm::shift_compare(
		a,
		c,
		::std::equal_to<int>());

// Outputs true
std::cout << "first_result: " << first_result << "\n";

// Outputs false
std::cout << "second_result: " << second_result << "\n";
//! [shift_compare]
}
}
