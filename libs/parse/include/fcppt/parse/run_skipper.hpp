//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_RUN_SKIPPER_HPP_INCLUDED
#define FCPPT_PARSE_RUN_SKIPPER_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/context_impl.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/state_impl.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch,
	typename Skipper
>
[[nodiscard]]
fcppt::parse::result<
	Ch,
	fcppt::unit
>
run_skipper(
	fcppt::reference<
		fcppt::parse::state<
			Ch
		>
	> const _state,
	fcppt::parse::context<
		Skipper
	> const &_context
)
{
	fcppt::parse::epsilon const skipper{};

	fcppt::parse::context<
		fcppt::parse::epsilon
	> const context{
		fcppt::make_cref(
			skipper
		)
	};

	return
		_context.skipper().get().parse(
			_state,
			context
		);
}

}
}

#endif
