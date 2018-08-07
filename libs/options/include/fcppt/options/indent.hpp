//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_INDENT_HPP_INCLUDED
#define FCPPT_OPTIONS_INDENT_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/indentation_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Indents every line of a string.

\ingroup fcpptvarious
*/
FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::string
indent(
	fcppt::string &&,
	fcppt::options::indentation
);

}
}

#endif
