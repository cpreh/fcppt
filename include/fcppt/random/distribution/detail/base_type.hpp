//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_DETAIL_BASE_TYPE_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_DETAIL_BASE_TYPE_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/random/distribution/detail/is_terminal.hpp>
#include <fcppt/random/distribution/transform/terminal.hpp>
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

template<
	typename Type,
	typename Enable = void
>
struct base_type;

template<
	typename Type
>
struct base_type<
	Type,
	typename
	std::enable_if<
		fcppt::random::distribution::detail::is_terminal<
			Type
		>::value
	>::type
>
{
	typedef Type type;
};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type
>
struct base_type<
	Type,
	typename
	std::enable_if<
		!fcppt::random::distribution::detail::is_terminal<
			Type
		>::value
	>::type
>
:
fcppt::random::distribution::detail::base_type<
	typename fcppt::random::distribution::transform<
		Type
	>::base_type
>
{
};

FCPPT_PP_POP_WARNING

}
}
}
}

#endif
