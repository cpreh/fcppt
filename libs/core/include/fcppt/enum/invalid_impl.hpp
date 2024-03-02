//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_INVALID_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_INVALID_IMPL_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/type_name_from_info.hpp>
#include <fcppt/cast/enum_to_underlying.hpp>
#include <fcppt/cast/promote_int.hpp>
#include <fcppt/enum/invalid_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <typeinfo> // IWYU pragma: keep
#include <fcppt/config/external_end.hpp>

template <typename Enum>
fcppt::enum_::invalid<Enum>::invalid(Enum const _enum)
    : fcppt::exception{
          FCPPT_TEXT("Invalid enum of type \"") +
          fcppt::from_std_string(fcppt::type_name_from_info(typeid(Enum))) +
          FCPPT_TEXT("\" and value \"") +
          fcppt::output_to_fcppt_string(
              fcppt::cast::promote_int(fcppt::cast::enum_to_underlying(_enum))) +
          FCPPT_TEXT("\".")}
{
}

#endif
