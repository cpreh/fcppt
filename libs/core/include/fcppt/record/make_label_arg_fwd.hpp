//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_MAKE_LABEL_ARG_FWD_HPP_INCLUDED
#define FCPPT_RECORD_MAKE_LABEL_ARG_FWD_HPP_INCLUDED

#include <fcppt/record/label_fwd.hpp>
#include <fcppt/record/detail/make_tag.hpp>
#include <fcppt/record/detail/tag_name.hpp>

/**
\brief Creates a parametrized #fcppt::record::label.

\ingroup fcpptrecord

Creates an #fcppt::record::label, passing it a unique,
implementation-defined tag type that depends on a template parameter.
The result is a template alias that still takes a parameter of type
\a arg.

\param name The name of the label type.

\param arg The type of the template parameter.
*/
#define FCPPT_RECORD_MAKE_LABEL_ARG(name, arg) \
  template <arg> \
  FCPPT_RECORD_DETAIL_MAKE_TAG(name); \
\
  template <arg arg_name> \
  using name = fcppt::record::label<FCPPT_RECORD_DETAIL_TAG_NAME(name) < arg_name>\
 >

#endif
