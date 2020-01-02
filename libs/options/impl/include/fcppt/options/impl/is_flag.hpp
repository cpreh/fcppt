//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_IMPL_IS_FLAG_HPP_INCLUDED
#define FCPPT_OPTIONS_IMPL_IS_FLAG_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/detail/flag_is_short.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{
namespace impl
{

fcppt::optional::object<
	std::pair<
		fcppt::options::detail::flag_is_short,
		fcppt::string
	>
>
is_flag(
	fcppt::string_view const &
);

}
}
}

#endif
