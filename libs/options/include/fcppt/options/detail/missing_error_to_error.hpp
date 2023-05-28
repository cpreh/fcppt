//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_MISSING_ERROR_TO_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_MISSING_ERROR_TO_ERROR_HPP_INCLUDED

#include <fcppt/options/error.hpp>
#include <fcppt/options/missing_error_variant_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options::detail
{
[[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::error
missing_error_to_error(fcppt::options::missing_error_variant &&);
}

#endif
