//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_IMPL_LEVEL_STRINGS_HPP_INCLUDED
#define FCPPT_LOG_IMPL_LEVEL_STRINGS_HPP_INCLUDED

#include <fcppt/enum_names_array_fwd.hpp>
#include <fcppt/enum_names_impl_fwd.hpp>
#include <fcppt/log/level_fwd.hpp>


namespace fcppt
{

template<>
struct enum_names_impl<
	fcppt::log::level
>
{
	static
	fcppt::enum_names_array<
		fcppt::log::level
	> const &
	get();
};

}

#endif
