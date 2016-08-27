//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_ISTREAM_FWD_HPP_INCLUDED
#define FCPPT_IO_ISTREAM_FWD_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{

/**
\brief Typedef to either std::istream or std::wistream, depending on fcppt::char_type
\ingroup fcpptstring


See the \link fcpptstring string module documentation \endlink for a motivation
for this.
*/
typedef
std::basic_istream<
	fcppt::char_type
>
istream;

}
}

#endif
