//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_WIDEN_STRING_HPP_INCLUDED
#define FCPPT_IO_WIDEN_STRING_HPP_INCLUDED

#include <fcppt/io/detail/widen_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{

/**
\brief Creates a string that outputs each character by widening

\ingroup fcpptio
*/
inline
fcppt::io::detail::widen_string
widen_string(
	std::string _string
)
{
	return
		fcppt::io::detail::widen_string(
			std::move(
				_string
			)
		);
}

}
}

#endif
