//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_GRAMMAR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_GRAMMAR_DECL_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/base_unique_ptr.hpp>
#include <fcppt/parse/grammar_fwd.hpp>
#include <fcppt/parse/result_of.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Result,
	typename Ch,
	typename Skipper
>
class grammar
{
	FCPPT_NONMOVABLE(
		grammar
	);
public:
	using
	grammar_base
	=
	grammar;

	using
	result_type
	=
	Result;

	using
	char_type
	=
	Ch;

	template<
		typename Type
	>
	using
	base_type
	=
	fcppt::parse::base_unique_ptr<
		Type,
		Ch,
		Skipper
	>;

	grammar(
		fcppt::reference<
			base_type<
				Result
			> const
		>,
		Skipper &&
	);

	~grammar();

	[[nodiscard]]
	base_type<
		Result
	> const &
	start() const;

	[[nodiscard]]
	Skipper const &
	skipper() const;

	template<
		typename Parser
	>
	[[nodiscard]]
	static
	base_type<
		fcppt::parse::result_of<
			Parser
		>
	>
	make_base(
		Parser &&
	);
private:
	fcppt::reference<
		base_type<
			Result
		> const
	> const start_;

	Skipper const skipper_;
};

}
}

#endif
