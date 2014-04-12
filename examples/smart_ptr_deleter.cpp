//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/c_deleter.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


int
main()
{
//! [c_deleter]
	typedef std::unique_ptr<
		void,
		fcppt::c_deleter
	> void_c_ptr;

	void_c_ptr ptr(
		std::malloc(
			100
		)
	);
//! [c_deleter]
}
//]
