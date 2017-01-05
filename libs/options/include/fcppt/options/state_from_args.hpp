//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_STATE_FROM_ARGS_HPP_INCLUDED
#define FCPPT_OPTIONS_STATE_FROM_ARGS_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/symbol.hpp>


namespace fcppt
{
namespace options
{

FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::options::state
state_from_args(
	fcppt::args_vector const &
);

}
}

#endif
