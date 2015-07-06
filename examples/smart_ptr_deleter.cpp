//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/c_deleter.hpp>
#include <fcppt/unique_ptr.hpp>


int
main()
{
//! [c_deleter]
	typedef fcppt::unique_ptr<
		void,
		fcppt::c_deleter<
			void
		>
	> void_c_ptr;

	void_c_ptr ptr(
		std::malloc(
			100
		)
	);
//! [c_deleter]
}
//]
