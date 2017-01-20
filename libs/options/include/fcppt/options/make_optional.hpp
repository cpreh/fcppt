//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MAKE_OPTIONAL_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_OPTIONAL_HPP_INCLUDED

#include <fcppt/options/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

template<
	typename Label,
	typename Parser
>
inline
fcppt::options::optional<
	Label,
	typename
	std::decay<
		Parser
	>::type
>
make_optional(
	Parser &&_parser
)
{
	return
		fcppt::options::optional<
			Label,
			typename
			std::decay<
				Parser
			>::type
		>{
			std::forward<
				Parser
			>(
				_parser
			)
		};
}

}
}

#endif
