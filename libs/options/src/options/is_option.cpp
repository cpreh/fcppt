//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string_view.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/maybe_front.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/copy_value.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/options/is_option.hpp>

bool fcppt::options::is_option(fcppt::string_view const &_value)
{
  return fcppt::optional::copy_value(fcppt::container::maybe_front(_value)) ==
         fcppt::optional::make(FCPPT_TEXT('-'));
}
