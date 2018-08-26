//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MAKE_MANY_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_MANY_HPP_INCLUDED

#include <fcppt/options/many_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Turns a parser into a many parser.

\ingroup fcpptoptions

Normally, a parser can be applied exactly once.
This function turns a parser into a parser that can be applied zero or more times.
*/
template<
	typename Parser
>
inline
fcppt::options::many<
	fcppt::type_traits::remove_cv_ref_t<
		Parser
	>
>
make_many(
	Parser &&_parser
)
{
	return
		fcppt::options::many<
			fcppt::type_traits::remove_cv_ref_t<
				Parser
			>
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
