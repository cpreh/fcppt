//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/join_strings.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>

int main()
{
  {
    //! [join_strings]
    std::vector<std::string> strings{"ab", "cd", "efg"};

    std::string const result{fcppt::algorithm::join_strings(strings, ",")};

    // Outputs "ab,cd,efg"
    std::cout << result << "\n";
    //! [join_strings]
  }
}
