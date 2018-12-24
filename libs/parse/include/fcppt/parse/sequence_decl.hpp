//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SEQUENCE_DECL_HPP_INCLUDED
#define FCPPT_PARSE_SEQUENCE_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/sequence_fwd.hpp>
#include <fcppt/parse/sequence_result.hpp>
#include <fcppt/parse/result_fwd.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Left,
	typename Right
>
class sequence
{
public:
	sequence(
		Left &&,
		Right &&
	);

	typedef
	decltype(
		fcppt::parse::sequence_result(
			std::declval<
				fcppt::parse::result_of<
					Left
				>
			>(),
			std::declval<
				fcppt::parse::result_of<
					Right
				>
			>()
		)
	)
	result_type;

	template<
		typename Ch,
		typename Skipper
	>
	fcppt::parse::result<
		result_type
	>
	parse(
		fcppt::reference<
			fcppt::parse::state<
				Ch
			>
		>,
		fcppt::parse::context<
			Skipper
		> const &
	) const;
private:
	Left left_;

	Right right_;
};

}
}

#endif
