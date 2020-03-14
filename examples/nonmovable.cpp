//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/nonmovable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace
{

//! [nonmovable]
class test_nonmovable
{
	FCPPT_NONMOVABLE(
		test_nonmovable
	);
public:
	test_nonmovable()
	:
		ptr_(new int(1))
	{
	}

	~test_nonmovable()
	{
		delete ptr_;
	}
private:
	int *ptr_;
};
//! [nonmovable]

}

int
main()
{
	test_nonmovable test1{};
}
