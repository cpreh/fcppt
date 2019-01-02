//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_REPETITION_PLUS_DECL_HPP_INCLUDED
#define FCPPT_PARSE_REPETITION_PLUS_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/repetition_plus_fwd.hpp>
#include <fcppt/parse/repetition_impl.hpp>
#include <fcppt/parse/repetition_result.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Parser
>
class repetition_plus
:
	private fcppt::parse::tag
{
public:
	explicit
	repetition_plus(
		Parser &&
	);

	typedef
	fcppt::parse::repetition_result<
		fcppt::parse::result_of<
			Parser
		>
	>
	result_type;

	template<
		typename Ch,
		typename Skipper
	>
	fcppt::parse::result<
		result_type
	>
	parse(
		fcppt::reference<
			fcppt::parse::state<
				Ch
			>
		>,
		fcppt::parse::context<
			Skipper
		> const &
	) const;
private:
	fcppt::parse::repetition<
		Parser
	> parser_;
};

}
}

#endif
