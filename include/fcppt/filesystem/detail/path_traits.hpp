//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_DETAIL_PATH_TRAITS_HPP_INCLUDED
#define FCPPT_FILESYSTEM_DETAIL_PATH_TRAITS_HPP_INCLUDED

#include <fcppt/config.h>
#include <boost/filesystem/path.hpp>

namespace fcppt
{
namespace filesystem
{
namespace detail
{

#ifdef FCPPT_NARROW_STRING
typedef boost::filesystem::path_traits path_traits;
#else
typedef boost::filesystem::wpath_traits path_traits;
#endif

}
}
}

#endif

