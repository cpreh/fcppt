//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IO_DETAIL_EXTRACT_HPP_INCLUDED
#define FCPPT_IO_DETAIL_EXTRACT_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/not.hpp>
#include <fcppt/io/detail/extract_impl.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_gnu_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::io::detail
{
template <typename Type, typename Ch, typename Traits>
inline std::
    enable_if_t<std::is_constructible_v<Type, fcppt::no_init>, fcppt::optional::object<Type>>
    extract(std::basic_istream<Ch, Traits> &_stream)
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GNU_GCC_WARNING(-Wmaybe-uninitialized)

  Type result{fcppt::no_init{}};

  FCPPT_PP_POP_WARNING

  return fcppt::io::detail::extract_impl(_stream, fcppt::make_ref(result));
}

template <typename Type, typename Ch, typename Traits>
inline std::enable_if_t<
    fcppt::not_(std::is_constructible_v<Type, fcppt::no_init>),
    fcppt::optional::object<Type>>
extract(std::basic_istream<Ch, Traits> &_stream)
{
  Type result;

  return fcppt::io::detail::extract_impl(_stream, fcppt::make_ref(result));
}

}

#endif
