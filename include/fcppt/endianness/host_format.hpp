//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_HOST_FORMAT_HPP_INCLUDED
#define FCPPT_ENDIANNESS_HOST_FORMAT_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/endianness/format_fwd.hpp>


namespace fcppt
{
namespace endianness
{

/**
\brief Returns the endianness of this machine

\ingroup fcpptendianness
*/
FCPPT_SYMBOL
fcppt::endianness::format
host_format();

}
}

#endif
