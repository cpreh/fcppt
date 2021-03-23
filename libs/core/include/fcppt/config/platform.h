//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONFIG_PLATFORM_H_INCLUDED
#define FCPPT_CONFIG_PLATFORM_H_INCLUDED

#if defined(_WIN32)
#define FCPPT_CONFIG_WINDOWS_PLATFORM
#elif defined(__unix__)
#define FCPPT_CONFIG_UNIX_PLATFORM
#elif defined(__APPLE__)
#define FCPPT_CONFIG_DARWIN_PLATFORM
#endif

#if defined(FCPPT_CONFIG_UNIX_PLATFORM) || defined(FCPPT_CONFIG_DARWIN_PLATFORM)
#define FCPPT_CONFIG_POSIX_PLATFORM
#endif

#endif
