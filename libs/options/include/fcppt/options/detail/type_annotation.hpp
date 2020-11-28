//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_TYPE_ANNOTATION_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_TYPE_ANNOTATION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/options/pretty_type.hpp>

namespace fcppt
{
namespace options
{
namespace detail
{
template <typename Type>
inline fcppt::string type_annotation()
{
  return FCPPT_TEXT(" : ") + fcppt::options::pretty_type<Type>();
}

}
}
}

#endif
