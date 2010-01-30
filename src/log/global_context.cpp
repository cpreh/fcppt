//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/global_context.hpp>
#include <fcppt/log/context.hpp>

fcppt::log::context &
fcppt::log::global_context()
{
	static context global_;

	return global_;
}
