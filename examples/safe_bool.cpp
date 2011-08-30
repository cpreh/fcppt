//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/safe_bool.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <iostream>
#include <fcppt/config/external_end.hpp>

namespace
{

//[safebool_example
class my_class
{
	FCPPT_SAFE_BOOL(my_class)
private:
	bool
	boolean_test() const
	{
		return isset_;
	}
public:
	explicit my_class(
		bool const _isset
	)
	:
		isset_(_isset)
	{}
private:
	bool isset_;
};
//]

}

int main()
{
//[safebool_usage
	my_class test(true);

	if(test)
		std::cout << "test is set\n";
//]
}
