//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_RUN_SKIPPER_HPP_INCLUDED
#define FCPPT_PARSE_RUN_SKIPPER_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/parse/context_impl.hpp>
#include <fcppt/parse/state.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Skipper
>
void
run_skipper(
	fcppt::reference<
		fcppt::parse::state
	> const _state,
	fcppt::parse::context<
		Skipper
	> const &_context
)
{
	fcppt::optional::maybe_void(
		_context.skipper(),
		[
			_state
		](
			fcppt::reference<
				Skipper const
			> const _skipper
		)
		{
			_skipper.get().run(
				_state.get().stream()
			);
		}
	);
}

}
}

#endif
