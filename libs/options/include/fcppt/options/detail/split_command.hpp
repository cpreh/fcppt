//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_SPLIT_COMMAND_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_SPLIT_COMMAND_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/string.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/detail/symbol.hpp>
#include <fcppt/tuple/object_impl.hpp>

namespace fcppt::options::detail
{
FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::optional::object<fcppt::tuple::object<fcppt::args_vector, fcppt::string, fcppt::args_vector>>
split_command(fcppt::args_vector const &, fcppt::options::option_name_set const &);

}

#endif
