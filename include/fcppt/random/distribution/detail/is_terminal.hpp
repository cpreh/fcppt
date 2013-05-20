//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_DETAIL_IS_TERMINAL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_DETAIL_IS_TERMINAL_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/random/distribution/detail/terminal_tag.hpp>
#include <fcppt/random/distribution/transform/terminal_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type
>
struct is_terminal
:
std::is_base_of<
	fcppt::random::distribution::detail::terminal_tag,
	fcppt::random::distribution::transform<
		Type
	>
>
{
};

FCPPT_PP_POP_WARNING

}
}
}
}

#endif
