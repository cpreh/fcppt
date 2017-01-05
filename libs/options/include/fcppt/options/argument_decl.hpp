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
class argument
{
public:
	explicit
	argument(
		fcppt::options::long_name const &
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
	fcppt::options::long_name long_name_;
};

}
}

#endif
