//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/copy_n.hpp>
#include <fcppt/algorithm/append.hpp>
#include <fcppt/algorithm/find_exn.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <string>
#include <ostream>
#include <iostream>

int main()
{
	typedef fcppt::container::raw_vector<
		unsigned char
	> vector_type;

	std::string const str("test");

	vector_type a(str.size());

	fcppt::algorithm::copy_n(str.data(), str.size(), a.data());

	a.push_back(' ');

	vector_type b(a);

	fcppt::algorithm::append(
		a,
		b
	);

	fcppt::algorithm::find_exn(
		str.begin(),
		str.end(),
		't'
	);

	std::cout << std::string(a.begin(), a.end()) << '\n';
}
