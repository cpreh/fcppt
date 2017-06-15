//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_COMBINE_ERRORS_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_COMBINE_ERRORS_HPP_INCLUDED

#include <fcppt/options/error.hpp>
#include <fcppt/options/detail/symbol.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::options::error
combine_errors(
	fcppt::options::error &&,
	fcppt::options::error &&
);

}
}
}

#endif
