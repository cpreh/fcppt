//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DETAIL_HAS_VALUE_ALL_HPP_INCLUDED
#define FCPPT_OPTIONAL_DETAIL_HAS_VALUE_ALL_HPP_INCLUDED

#include <fcppt/identity.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{
namespace detail
{

template<
	typename... Optionals
>
inline
bool
has_value_all(
	Optionals const &... _optionals
)
{
	return
		fcppt::algorithm::all_of(
			std::array<
				bool,
				sizeof...(
					Optionals
				)
			>{{
				_optionals.has_value()...
			}},
			fcppt::identity{}
		);
}

}
}
}

#endif
