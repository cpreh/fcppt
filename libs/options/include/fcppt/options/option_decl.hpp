//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OPTION_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/option_fwd.hpp>
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
class option
{
public:
	FCPPT_MAKE_STRONG_TYPEDEF(
		fcppt::optional::object<
			Type
		>,
		optional_default_value
	);

	option(
		fcppt::options::optional_short_name const &,
		fcppt::options::long_name const &,
		optional_default_value const &
	);

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			Label,
			Type
		>
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

	optional_default_value default_value_;
};

}
}

#endif
