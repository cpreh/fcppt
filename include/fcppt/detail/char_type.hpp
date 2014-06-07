//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_CHAR_TYPE_HPP_INCLUDED
#define FCPPT_DETAIL_CHAR_TYPE_HPP_INCLUDED

#include <fcppt/public_config.hpp>


namespace fcppt
{
namespace detail
{

#if defined(FCPPT_NARROW_STRING)
typedef char char_type;
#else
typedef wchar_t char_type;
#endif

}
}

#endif
