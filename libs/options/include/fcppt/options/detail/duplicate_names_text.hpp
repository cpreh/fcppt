//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_DUPLICATE_NAMES_TEXT_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_DUPLICATE_NAMES_TEXT_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/name_set.hpp>
#include <fcppt/options/detail/symbol.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::string
duplicate_names_text(
	fcppt::options::name_set const &
);

}
}
}

#endif
