//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assign/make_container.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

int
main()
{

{
//! [make_container]
typedef std::vector<int> container;

container result;

result = fcppt::assign::make_container<container>(1)(2)(3);
// Result now contains 1,2,3
result = fcppt::assign::make_container<container>(1)(2)(3).container();
// The same, but more explicit (might be needed inside templates)
//! [make_container]
}
}
