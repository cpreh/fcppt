//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_DETAIL_GCC_VERSION_AT_LEAST_H_INCLUDED
#define FCPPT_CONFIG_DETAIL_GCC_VERSION_AT_LEAST_H_INCLUDED

#include <fcppt/config/compiler.h>


#if defined(FCPPT_CONFIG_GCC_COMPILER) && !defined(FCPPT_CONFIG_CLANG_COMPILER)

#include <fcppt/config/detail/major_minor_at_least.h>


#define FCPPT_CONFIG_DETAIL_GCC_VERSION_AT_LEAST(\
	major,\
	minor\
) \
FCPPT_CONFIG_DETAIL_MAJOR_MINOR_AT_LEAST(\
	major,\
	__GNUC__,\
	minor,\
	__GNUC_MINOR__\
)

#else

#define FCPPT_CONFIG_DETAIL_GCC_VERSION_AT_LEAST(\
	major,\
	minor\
) \
false

#endif

#endif
