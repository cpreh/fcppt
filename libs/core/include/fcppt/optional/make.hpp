//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_MAKE_HPP_INCLUDED
#define FCPPT_OPTIONAL_MAKE_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Wraps a value into an optional

\ingroup fcpptoptional
*/
template<
	typename Type
>
inline
fcppt::optional::object<
	typename
	std::decay<
		Type
	>::type
>
make(
	Type &&_value
)
{
	return
		fcppt::optional::object<
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
