//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[weakptr
#include <fcppt/shared_ptr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/weak_ptr.hpp>
#include <fcppt/io/cout.hpp>


int main()
{
	typedef fcppt::weak_ptr<
		int
	> weak_int_ptr;

	typedef fcppt::shared_ptr<
		int
	> shared_int_ptr;

	shared_int_ptr ip(
		new int(42)
	);

	weak_int_ptr weak_p(
		ip
	);

	{
		shared_int_ptr x = weak_p.lock();

		// x will be != 0
		fcppt::io::cout()
			<< x
			<< FCPPT_TEXT('\n');
	}

	// delete the shared pointer
	ip.reset();

	{
		shared_int_ptr x = weak_p.lock();

		// x will be 0
		fcppt::io::cout()
			<< x
			<< FCPPT_TEXT('\n');
	}
}
//]
