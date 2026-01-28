//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_TAG_NAME_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_TAG_NAME_HPP_INCLUDED

#include <fcppt/preprocessor/cat.hpp>
#include <fcppt/record/detail/tag_suffix.hpp>

#define FCPPT_RECORD_DETAIL_TAG_NAME(name) FCPPT_PP_CAT(name, FCPPT_RECORD_DETAIL_TAG_SUFFIX)

#endif
