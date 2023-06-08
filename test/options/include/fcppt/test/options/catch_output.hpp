//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TEST_OPTIONS_CATCH_OUTPUT_HPP_INCLUDED
#define FCPPT_TEST_OPTIONS_CATCH_OUTPUT_HPP_INCLUDED

#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/catch/convert.hpp>
#include <fcppt/options/error_fwd.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace Catch
{
template <>
struct StringMaker<fcppt::options::error>
{
  static std::string convert(fcppt::options::error const &_value)
  {
    return fcppt::catch_::convert(fcppt::output_to_fcppt_string(_value));
  }
};
}

#endif
