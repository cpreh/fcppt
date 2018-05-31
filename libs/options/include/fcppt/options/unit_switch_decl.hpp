//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_UNIT_SWITCH_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_UNIT_SWITCH_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/long_name_fwd.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/optional_short_name_fwd.hpp>
#include <fcppt/options/parse_arguments_fwd.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/switch_impl.hpp>
#include <fcppt/options/unit_switch_fwd.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/variadic_fwd.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A required switch.

\ingroup fcpptoptions

This parser is similar to \link fcppt::options::switch_\endlink but it
requires its switch to be specified.
*/
template<
	typename Label
>
class unit_switch
{
	typedef
	fcppt::options::switch_<
		Label
	>
	impl;
public:
	/**
	\brief Constructs a switch parser.

	\param short_name An optional short name ("-f") this parser will match.

	\param long_name The long name ("--flag") this parser will match.
	*/
	unit_switch(
		fcppt::options::optional_short_name &&short_name,
		fcppt::options::long_name &&long_name
	);

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			Label,
			fcppt::unit
		>
	>
	result_type;

	fcppt::options::result<
		result_type
	>
	parse(
		fcppt::options::parse_arguments &
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
