//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_ARGUMENT_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_ARGUMENT_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/argument_fwd.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/record/element_fwd.hpp>
#include <fcppt/record/variadic_fwd.hpp>


namespace fcppt
{
namespace options
{

/**
\brief An argument parser

\ingroup fcpptoptions

Argument parsers match the next command-line parameter that is not a flag
("-f"/"--flag") or an option ("-o value"/"--option value""). The result is
stored in a record that has a single element with label \a Label and type \a
Type. In case reading the value into \a Type fails, the parser also fails.

\tparam Label An \link fcppt::record::label\endlink.

\tparam Type The type of the argument's value which must be readable from an
\link fcppt::io::istream\endlink.
*/
template<
	typename Label,
	typename Type
>
class argument
{
public:
	/**
	\brief Constructs an argument parser.

	\param long_name The name of the argument as displayed in usage output.

	\param help_text Optional help text for this argument.
	*/
	argument(
		fcppt::options::long_name const &long_name,
		fcppt::options::optional_help_text const &help_text
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
	fcppt::options::long_name long_name_;

	fcppt::options::optional_help_text help_text_;
};

}
}

#endif
