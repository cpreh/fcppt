//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SEQUENCE_DECL_HPP_INCLUDED
#define FCPPT_PARSE_SEQUENCE_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/sequence_fwd.hpp>
#include <fcppt/parse/sequence_result.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace fcppt
{
namespace parse
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

template<
	typename Left,
	typename Right
>
class sequence
:
	private fcppt::parse::tag
{
public:
	sequence(
		Left &&,
		Right &&
	);

	typedef
	fcppt::parse::sequence_result<
		fcppt::parse::result_of<
			Left
		>,
		fcppt::parse::result_of<
			Right
		>
	>
	result_type;

	template<
		typename Ch,
		typename Skipper
	>
	fcppt::parse::result<
		Ch,
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
	Left left_;

	Right right_;
};

FCPPT_PP_POP_WARNING

}
}

#endif
