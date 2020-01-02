//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_NAMED_DECL_HPP_INCLUDED
#define FCPPT_PARSE_NAMED_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/named_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

template<
	typename Ch,
	typename Parser
>
class named
:
	private fcppt::parse::tag
{
public:
	named(
		Parser &&,
		std::basic_string<
			Ch
		> &&
	);

	typedef
	fcppt::parse::result_of<
		Parser
	>
	result_type;

	template<
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
	Parser parser_;

	std::basic_string<
		Ch
	> name_;
};

FCPPT_PP_POP_WARNING

template<
	typename Ch,
	typename Parser
>
named(
	Parser &&,
	std::basic_string<
		Ch
	> &&
)
->
named<
	Ch,
	fcppt::type_traits::remove_cv_ref_t<
		Parser
	>
>;

}
}

#endif
