//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_SUM_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_SUM_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/left_fwd.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/right_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/sum_fwd.hpp>
#include <fcppt/record/element_fwd.hpp>
#include <fcppt/record/variadic_fwd.hpp>
#include <fcppt/variant/variadic_fwd.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A sum of two parsers.

\ingroup fcpptoptions

This parser first tries its left parser and if that succeeds returns its result.
Otherwise, it tries the right parser and returns its result.
*/
template<
	typename Label,
	typename Left,
	typename Right
>
class sum
{
public:
	sum(
		Left &&,
		Right &&
	);

	sum(
		sum const &
	);

	sum(
		sum &&
	);

	sum &
	operator=(
		sum const &
	);

	sum &
	operator=(
		sum &&
	);

	~sum();

	typedef
	fcppt::options::result_of<
		Left
	>
	left_result;

	struct left
	{
		typedef
		left_result
		result_type;
	};

	typedef
	fcppt::options::result_of<
		Right
	>
	right_result;

	struct right
	{
		typedef
		right_result
		result_type;
	};

	typedef
	fcppt::variant::variadic<
		fcppt::options::left<
			left_result
		>,
		fcppt::options::right<
			right_result
		>
	>
	variant;

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			Label,
			variant
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
	Left left_;

	Right right_;
};

}
}

#endif
