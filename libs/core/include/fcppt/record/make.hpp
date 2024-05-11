//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_MAKE_HPP_INCLUDED
#define FCPPT_RECORD_MAKE_HPP_INCLUDED

#include <fcppt/mpl/list/distinct.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_init_tag.hpp>
#include <fcppt/record/element_init_type.hpp>
#include <fcppt/record/label_impl.hpp>
#include <fcppt/record/is_vararg_ctor.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::record
{
/**
\brief Creates a record from an initializer list.

\ingroup fcpptrecord

<code>Args</code> must be created using <code>label{} = value</code> expressions.
*/
template <typename... Args>
[[nodiscard]] inline fcppt::record::object<fcppt::record::element<
    fcppt::record::label<fcppt::record::element_init_tag<Args>>,
    fcppt::record::element_init_type<Args>>...>
make(Args &&..._args)
  requires(
      fcppt::mpl::list::distinct<fcppt::mpl::list::object<
          fcppt::record::label<fcppt::record::element_init_tag<Args>>...>>::value &&
      fcppt::record::is_vararg_ctor<Args...>::value)
{
  return fcppt::record::object<fcppt::record::element<
      fcppt::record::label<fcppt::record::element_init_tag<Args>>,
      fcppt::record::element_init_type<Args>>...>{std::forward<Args>(_args)...};
}
}

#endif
