//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/append.hpp>
#include <fcppt/algorithm/join_strings.hpp>
#include <fcppt/config/external_begin.hpp>
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
std::vector<int> v{1,2,3};
std::vector<int> w{4,5};

fcppt::algorithm::append(
	v,
	w
);

// Now v contains: 1,2,3,4,5
//! [append]
}

{
//! [join_strings]
std::vector<std::string> strings{
	"ab",
	"cd",
	"efg"
};

std::string const result{
	fcppt::algorithm::join_strings(
		strings,
		","
	)
};

// Outputs "ab,cd,efg"
std::cout << result << "\n";
//! [join_strings]
}

}
