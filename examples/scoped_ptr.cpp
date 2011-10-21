//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[scopedptr
#include <fcppt/c_deleter.hpp>
#include <fcppt/scoped_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


int main()
{
	typedef fcppt::scoped_ptr<
		int
	> int_ptr;

	int_ptr p1(
		new int(42)
	);

	typedef fcppt::scoped_ptr<
		void,
		fcppt::c_deleter
	> void_c_ptr;

	void_c_ptr p2(
		std::malloc(
			100
		)
	);
}
//]
