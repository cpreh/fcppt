//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_SWITCH_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_SWITCH_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/flag_impl.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/switch_fwd.hpp>


namespace fcppt
{
namespace options
{

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
	switch_(
		fcppt::options::optional_short_name const &,
		fcppt::options::long_name const &
	);

	typedef
	typename
	impl::result_type
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
	impl impl_;
};

}
}

#endif
