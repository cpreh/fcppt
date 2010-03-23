//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[noncopyable
#include <fcppt/noncopyable.hpp>

class test
{
	FCPPT_NONCOPYABLE(test)
public:
	void
	some_function()
	{
	}
};
//]

int main()
{}
