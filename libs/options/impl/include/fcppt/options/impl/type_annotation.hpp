//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_IMPL_TYPE_ANNOTATION_HPP_INCLUDED
#define FCPPT_OPTIONS_IMPL_TYPE_ANNOTATION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/options/type_name.hpp>

namespace fcppt::options::impl
{
[[nodiscard]] inline fcppt::string type_annotation(fcppt::options::type_name const &_type)
{
  return FCPPT_TEXT(" : ") + _type.get();
}
}

#endif
