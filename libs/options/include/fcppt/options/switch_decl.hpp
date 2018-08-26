//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_SWITCH_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_SWITCH_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/flag_impl.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/long_name_fwd.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/optional_help_text_fwd.hpp>
#include <fcppt/options/optional_short_name_fwd.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/switch_fwd.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A switch parser.

\ingroup fcpptoptions

A switch parser is similar to \link fcppt::options::flag\endlink, but its value
type is fixed to <code>bool</code>, where its active value is <code>true</code>
and its inactive value is <code>false</code>.
*/
template<
	typename Label
>
class switch_
{
	typedef
	fcppt::options::flag<
		Label,
		bool
	>
	impl;
public:
	/**
	\brief Constructs a switch parser.

	\param short_name An optional short name ("-f") this parser will match.

	\param long_name The long name ("--flag") this parser will match.

	\param help_text Optional help text for this flag.
	*/
	switch_(
		fcppt::options::optional_short_name &&short_name,
		fcppt::options::long_name &&long_name,
		fcppt::options::optional_help_text &&help_text
	);

	typedef
	typename
	impl::result_type
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

	fcppt::options::optional_short_name const &
	short_name() const;

	fcppt::options::long_name const &
	long_name() const;
private:
	impl impl_;
};

}
}

#endif
