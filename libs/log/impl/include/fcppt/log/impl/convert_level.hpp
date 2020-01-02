//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_IMPL_CONVERT_LEVEL_HPP_INCLUDED
#define FCPPT_LOG_IMPL_CONVERT_LEVEL_HPP_INCLUDED

#include <fcppt/log/optional_level_fwd.hpp>
#include <fcppt/log/detail/active_level_int.hpp>


namespace fcppt
{
namespace log
{
namespace impl
{

fcppt::log::detail::active_level_int
convert_level(
	fcppt::log::optional_level const &
);

}
}
}

#endif
