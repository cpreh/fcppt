//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_MSVC_VERSION_AT_LEAST_HPP_INCLUDED
#define FCPPT_CONFIG_MSVC_VERSION_AT_LEAST_HPP_INCLUDED

#include <fcppt/config/detail/msvc_version_at_least.hpp>


/**
\brief Checks if the msvc is being used and its version is at least \a version.

\ingroup fcpptconfig
*/
#define FCPPT_CONFIG_MSVC_VERSION_AT_LEAST(\
	version\
) \
FCPPT_CONFIG_DETAIL_MSVC_VERSION_AT_LEAST(\
	version\
)

#endif
