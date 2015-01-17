//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_TRANSFORM_TERMINAL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_TRANSFORM_TERMINAL_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/random/distribution/detail/terminal_tag.hpp>
#include <fcppt/random/distribution/transform/terminal_fwd.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type,
	typename Enable
>
struct transform
:
fcppt::random::distribution::detail::terminal_tag
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
