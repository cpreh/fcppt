//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_ELEMENT_INIT_DECL_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_ELEMENT_INIT_DECL_HPP_INCLUDED

#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/detail/element_init_fwd.hpp>
#include <fcppt/record/detail/is_tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace record
{
namespace detail
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4521)
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

template <typename Tag, typename Type>
class element_init
{
public:
  using tag = Tag;

  using value_type = Type;

  static_assert(!std::is_lvalue_reference_v<value_type>, "Type must not be a reference");

  static_assert(fcppt::record::detail::is_tag<Tag>::value, "Tag must be a tag");

  explicit element_init(value_type);

  value_type &value();

private:
  value_type value_;
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
