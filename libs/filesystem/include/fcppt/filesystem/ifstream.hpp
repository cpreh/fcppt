//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_IFSTREAM_HPP_INCLUDED
#define FCPPT_FILESYSTEM_IFSTREAM_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <fstream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Typedef to <code>basic_ifstream</code>, depending on fcppt::char_type.

\ingroup fcpptstring
*/
typedef
std::basic_ifstream<
	fcppt::char_type
>
ifstream;

}
}

#endif
