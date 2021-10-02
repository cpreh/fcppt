//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CATCH_DETAIL_IGNORE_RESERVED_IDENTIFIERS_HPP_INCLUDED
#define FCPPT_CATCH_DETAIL_IGNORE_RESERVED_IDENTIFIERS_HPP_INCLUDED

#include <fcppt/config/clang_version_at_least.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>

#if FCPPT_CONFIG_CLANG_VERSION_AT_LEAST(13,0)
#define FCPPT_CATCH_DETAIL_IGNORE_RESERVED_IDENTIFIERS \
FCPPT_PP_DISABLE_CLANG_WARNING(-Wreserved-identifier)
#else
#define FCPPT_CATCH_DETAIL_IGNORE_RESERVED_IDENTIFIERS
#endif

#endif
