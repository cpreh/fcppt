//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_STATE_HPP_INCLUDED
#define FCPPT_OPTIONS_STATE_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/optional_std_string_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <unordered_map>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

class state
{
public:
	typedef
	unsigned
	flag_count;

	typedef
	std::unordered_map<
		std::string,
		flag_count
	>
	flag_map;

	typedef
	std::unordered_map<
		std::string,
		fcppt::args_vector
	>
	options_map;

	FCPPT_OPTIONS_DETAIL_SYMBOL
	state(
		fcppt::args_vector &&,
		flag_map &&,
		options_map &&
	);

	FCPPT_OPTIONS_DETAIL_SYMBOL
	fcppt::optional_std_string
	pop_arg();

	FCPPT_OPTIONS_DETAIL_SYMBOL
	bool
	pop_flag(
		std::string const &
	);

	FCPPT_OPTIONS_DETAIL_SYMBOL
	fcppt::optional_std_string
	pop_option(
		std::string const &
	);
private:
	fcppt::args_vector args_;

	flag_map flags_;

	options_map options_;
};

}
}

#endif
