//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_IMPL_FLAG_NAME_HPP_INCLUDED
#define FCPPT_OPTIONS_IMPL_FLAG_NAME_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/detail/flag_is_short.hpp>


namespace fcppt
{
namespace options
{
namespace impl
{

fcppt::string
flag_name(
	fcppt::string const &,
	fcppt::options::detail::flag_is_short
);

}
}
}

#endif
