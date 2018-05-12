//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_SUM_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_SUM_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_arguments_fwd.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/sum_fwd.hpp>
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
	typename Left,
	typename Right
>
class sum
{
public:
	sum(
		Left const &,
		Right const &
	);

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
	fcppt::variant::variadic<
		fcppt::options::result_of<
			Left
		>,
		fcppt::options::result_of<
			Right
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
private:
	Left left_;

	Right right_;
};

}
}

#endif
