//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_UTF8_UCS4_HPP_INCLUDED
#define FCPPT_SRC_UTF8_UCS4_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <fcppt/config/external_end.hpp>
 

namespace fcppt
{
namespace utf8
{

// typedef wchar_t ucs4; // TODO: is this right? -> No it is not
typedef boost::int32_t ucs4; 

}
}

#endif
