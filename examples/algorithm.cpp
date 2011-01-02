//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[algorithm
#include <fcppt/algorithm/append.hpp>
#include <fcppt/algorithm/contains.hpp>
#include <fcppt/algorithm/copy_n.hpp>
#include <fcppt/algorithm/find_exn.hpp>
#include <fcppt/algorithm/join_strings.hpp>
#include <fcppt/algorithm/ptr_container_erase.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <string>
#include <vector>
#include <ostream>
#include <iostream>

int main()
{
	typedef 
	fcppt::container::raw_vector<unsigned char> 
	vector_type;

	std::string const str("test");

	vector_type a(str.size());

	// copy_n
	fcppt::algorithm::copy_n(
		str.data(), 
		str.size(), 
		a.data()
	);

	a.push_back(' ');

	vector_type b(a);

	// append
	fcppt::algorithm::append(
		a,
		b
	);

	// find_exn
	fcppt::algorithm::find_exn(
		str.begin(),
		str.end(),
		't'
	);

	std::cout << std::string(a.begin(), a.end()) << '\n';

	// contains
	std::cout << "Vector contains 's':" << fcppt::algorithm::contains(a.begin(),a.end(),'s') << "\n";

	typedef
	std::vector<std::string>
	string_vector;

	string_vector strings;
	strings.push_back("foo");
	strings.push_back("bar");
	strings.push_back("baz");

	// join_strings, outputs "foo|bar|baz"
	std::cout << fcppt::algorithm::join_strings(strings,"|") << "\n";

	typedef
	boost::ptr_vector<std::string>
	ptr_container;

	ptr_container ptrs;
	ptrs.push_back(new std::string("foo"));
	ptrs.push_back(new std::string("bar"));

	std::string * const ptr = &(ptrs.back());

	// ptr_container_erase, deletes "bar"
	fcppt::algorithm::ptr_container_erase(
		ptrs,
		ptr);
}
//]
