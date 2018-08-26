//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args.hpp>
#include <fcppt/args_char.hpp>
#include <fcppt/args_from_second.hpp>
#include <fcppt/args_vector.hpp>


fcppt::args_vector
fcppt::args_from_second(
	int const _argc,
	fcppt::args_char const *const *const _argv
)
{
	return
		_argc
		==
		0
		?
			fcppt::args_vector{}
		:
			fcppt::args(
				_argc
				-
				1,
				_argv
				+
				1
			)
		;
}
