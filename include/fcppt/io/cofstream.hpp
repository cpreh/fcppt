//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_COFSTREAM_HPP_INCLUDED
#define FCPPT_IO_COFSTREAM_HPP_INCLUDED

#include <fcppt/filesystem/config.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/fstream.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace io
{

/**
\brief A boost::filesystem::ifstream to write files byte-wise
\ingroup fcpptstring


See the \link fcpptstring string module documentation \endlink for a motivation
for this.
*/
typedef boost::filesystem::ofstream cofstream;

}
}

#endif
