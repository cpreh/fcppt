//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_LABEL_NAME_HPP_INCLUDED
#define FCPPT_RECORD_LABEL_NAME_HPP_INCLUDED

#include <fcppt/type_name_from_info.hpp>
#include <fcppt/preprocessor/stringize_narrow.hpp>
#include <fcppt/record/is_label.hpp>
#include <fcppt/record/detail/tag_suffix.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <string_view>
#include <typeinfo> // IWYU pragma: keep
#include <fcppt/config/external_end.hpp>

namespace fcppt::record
{
/**
\brief Returns the name of a label as a string.

\ingroup fcpptrecord
*/
template <typename Label>
inline std::string label_name()
  requires(fcppt::record::is_label<Label>::value)
{
  std::string const ret{fcppt::type_name_from_info(typeid(typename Label::tag))};
  std::string_view ret_view{ret};
  std::string_view const suffix{FCPPT_PP_STRINGIZE_NARROW(FCPPT_RECORD_DETAIL_TAG_SUFFIX)};
  ret_view.remove_suffix(suffix.size());
  return std::string{ret_view};
}
}

#endif
