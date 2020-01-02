//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MANY_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_MANY_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/many_fwd.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/map_elements.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief A parser for zero or more elements.

\ingroup fcpptoptions

Wraps a parser such that it may apply zero or more times. The result type is a
record that adds one layer of <code>std::vector</code> to the elements of the
result type of \a Parser.

\see fcppt::options::make_many
*/
template<
	typename Parser
>
class many
{
public:
	explicit
	many(
		Parser &&
	);

	typedef
	fcppt::record::map_elements<
		fcppt::options::result_of<
			Parser
		>,
		::metal::bind<
			::metal::lambda<
				std::vector
			>,
			::metal::bind<
				::metal::lambda<
					fcppt::record::element_to_type
				>,
				::metal::_1
			>
		>
	>
	result_type;

	fcppt::options::parse_result<
		result_type
	>
	parse(
		fcppt::options::state &&,
		fcppt::options::parse_context const &
	) const;

	fcppt::options::flag_name_set
	flag_names() const;

	fcppt::options::option_name_set
	option_names() const;

	fcppt::string
	usage() const;
private:
	Parser parser_;
};

FCPPT_PP_POP_WARNING

}
}

#endif
