//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace
{

//! [noncopyable]
class test_noncopyable
{
	FCPPT_NONCOPYABLE(
		test_noncopyable
	);
public:
	test_noncopyable()
	:
		ptr_(new int(42))
	{
	}

	~test_noncopyable()
	{
		delete ptr_;
	}
private:
	int *ptr_;
};
//! [noncopyable]

}

int
main()
{
	test_noncopyable test1{};
}
