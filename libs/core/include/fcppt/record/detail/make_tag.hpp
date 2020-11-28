//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_MAKE_TAG_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_MAKE_TAG_HPP_INCLUDED

#include <fcppt/record/detail/tag_base.hpp>
#include <fcppt/record/detail/tag_name.hpp>

#define FCPPT_RECORD_DETAIL_MAKE_TAG(name) \
  struct FCPPT_RECORD_DETAIL_TAG_NAME(name) \
      : \
\
        fcppt::record::detail::tag_base \
  { \
  }

#endif
