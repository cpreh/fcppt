//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_ERROR_VARIANT_FWD_HPP_INCLUDED
#define FCPPT_PARSE_ERROR_VARIANT_FWD_HPP_INCLUDED

#include <fcppt/parse/alternative_error_fwd.hpp>
#include <fcppt/parse/basic_char_error_fwd.hpp>
#include <fcppt/parse/basic_char_set_error_fwd.hpp>
#include <fcppt/parse/basic_literal_error_fwd.hpp>
#include <fcppt/parse/basic_string_error_fwd.hpp>
#include <fcppt/parse/complement_error_fwd.hpp>
#include <fcppt/parse/custom_error_fwd.hpp>
#include <fcppt/parse/fail_error_fwd.hpp>
#include <fcppt/parse/named_error_fwd.hpp>
#include <fcppt/parse/typed_error_fwd.hpp>
#include <fcppt/variant/object_fwd.hpp>

namespace fcppt::parse
{

template <typename Ch>
using error_variant = fcppt::variant::object<
    fcppt::parse::alternative_error<Ch>,
    fcppt::parse::basic_char_error<Ch>,
    fcppt::parse::basic_char_set_error<Ch>,
    fcppt::parse::basic_literal_error<Ch>,
    fcppt::parse::basic_string_error<Ch>,
    fcppt::parse::complement_error<Ch>,
    fcppt::parse::custom_error<Ch>,
    fcppt::parse::fail_error<Ch>,
    fcppt::parse::named_error<Ch>,
    fcppt::parse::typed_error<Ch>>;
}

#endif
