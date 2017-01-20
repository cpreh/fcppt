//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_FLAG_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_FLAG_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/options/flag_fwd.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/record/element_fwd.hpp>
#include <fcppt/record/variadic_fwd.hpp>


namespace fcppt
{
namespace options
{

template<
	typename Label,
	typename Type
>
class flag
{
public:
	FCPPT_MAKE_STRONG_TYPEDEF(
		Type,
		active_value
	);

	FCPPT_MAKE_STRONG_TYPEDEF(
		Type,
		inactive_value
	);

	flag(
		fcppt::options::optional_short_name const &,
		fcppt::options::long_name const &,
		active_value const &,
		inactive_value const &,
		fcppt::options::optional_help_text const &
	);

	typedef
	fcppt::record::element<
		Label,
		Type
	>
	element_type;

	typedef
	fcppt::record::variadic<
		element_type
	>
	result_type;

	fcppt::options::result<
		result_type
	>
	parse(
		fcppt::options::state &
	) const;

	fcppt::options::has_parameter_set
	parameters() const;

	fcppt::string
	usage() const;
private:
	fcppt::options::optional_short_name short_name_;

	fcppt::options::long_name long_name_;

	active_value active_value_;

	inactive_value inactive_value_;

	fcppt::options::optional_help_text help_text_;
};

}
}

#endif
