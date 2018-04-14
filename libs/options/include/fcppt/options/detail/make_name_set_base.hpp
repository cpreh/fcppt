//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_MAKE_NAME_SET_BASE_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_MAKE_NAME_SET_BASE_HPP_INCLUDED

#include <fcppt/options/long_name_fwd.hpp>
#include <fcppt/options/name_set.hpp>
#include <fcppt/options/optional_short_name_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::options::name_set
make_name_set_base(
	fcppt::options::long_name const &,
	fcppt::options::optional_short_name const &
);

}
}
}

#endif
