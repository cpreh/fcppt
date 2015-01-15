//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_CLANG_VERSION_AT_LEAST_H_INCLUDED
#define FCPPT_CONFIG_CLANG_VERSION_AT_LEAST_H_INCLUDED

#include <fcppt/config/detail/clang_version_at_least.h>


/**
\brief Checks if the clang is being used and its version is at least (major,
minor)

\ingroup fcpptconfig
*/
#define FCPPT_CONFIG_CLANG_VERSION_AT_LEAST(\
	major,\
	minor\
) \
FCPPT_CONFIG_DETAIL_CLANG_VERSION_AT_LEAST(\
	major,\
	minor\
)

#endif
