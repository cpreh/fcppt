//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_UNIT_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_UNIT_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/unit_fwd.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_arguments_fwd.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/unit_fwd.hpp>
#include <fcppt/record/element_fwd.hpp>
#include <fcppt/record/variadic_fwd.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A parser that always succeeds.

\ingroup fcpptoptions

\tparam Label An \link fcppt::record::label\endlink.
*/
template<
	typename Label
>
class unit
{
public:
	unit();

	typedef
	fcppt::record::element<
		Label,
		fcppt::unit
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
		fcppt::options::parse_arguments &
	) const;

	fcppt::options::flag_name_set
	flag_names() const;

	fcppt::options::option_name_set
	option_names() const;

	fcppt::string
	usage() const;
};

}
}

#endif
