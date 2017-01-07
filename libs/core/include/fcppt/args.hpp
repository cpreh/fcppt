//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ARGS_HPP_INCLUDED
#define FCPPT_ARGS_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/detail/symbol.hpp>


namespace fcppt
{

/**
\brief Copy main arguments into a container

This function is only useful for command line arguments received in
<code>main</code>. To handle Windows arguments, see the
<code>GetCommandLine</code> function.

\ingroup fcpptvarious
*/
FCPPT_DETAIL_SYMBOL
fcppt::args_vector
args(
	int argc,
	char **argv
);

}

#endif
