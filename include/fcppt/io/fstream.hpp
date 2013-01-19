//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_FSTREAM_HPP_INCLUDED
#define FCPPT_IO_FSTREAM_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/fstream.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{

/**
\brief Typedef to either boost::filesystem::fstream or boost::filesystem::wfstream, depending on fcppt::char_type
\ingroup fcpptstring


See the \link fcpptstring string module documentation \endlink for a motivation
for this.
*/
typedef boost::filesystem::basic_fstream<
	fcppt::char_type
> fstream;

}
}

#endif
