//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/safe_bool.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace
{

//! [safe_bool_declaration]
class my_class
{
	// Implement the safe bool idiom for this class
	FCPPT_SAFE_BOOL(
		my_class
	)
private:
	// We must also implement this function to tell when the object is
	// supposed to be true.
	bool
	boolean_test() const
	{
		return isset_;
	}
public:
	explicit
	my_class(
		bool const _isset
	)
	:
		isset_(
			_isset
		)
	{
	}
private:
	bool isset_;
};
//! [safe_bool_declaration]

}

int
main()
{
//! [safe_bool_usage]
	my_class test(
		true
	);

	if(
		test
	)
		std::cout << "test is set\n";
//! [safe_bool_usage]
}
