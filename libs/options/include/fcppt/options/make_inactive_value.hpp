//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MAKE_INACTIVE_VALUE_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_INACTIVE_VALUE_HPP_INCLUDED

#include <fcppt/options/inactive_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Creates an inactive value

\ingroup fcpptoptions
*/
template<
	typename Type
>
inline
fcppt::options::inactive_value<
	typename
	std::decay<
		Type
	>::type
>
make_inactive_value(
	Type &&_value
)
{
	return
		fcppt::options::inactive_value<
			typename
			std::decay<
				Type
			>::type
		>{
			std::forward<
				Type
			>(
				_value
			)
		};

}

}
}

#endif
