//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


// ![include_external]
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>
// ![include_external]

// ![gcc_warning]
#include <fcppt/config/gcc_version_at_least.hpp>

#if FCPPT_CONFIG_GCC_VERSION_AT_LEAST(4, 9) && !FCPPT_CONFIG_GCC_VERSION_AT_LEAST(6, 0)
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
FCPPT_PP_DISABLE_GCC_WARNING(-Wfloat-conversion)
#endif
// ![gcc_warning]

int
main()
{
}
