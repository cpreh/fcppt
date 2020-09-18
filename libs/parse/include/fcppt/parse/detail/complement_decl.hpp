//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_COMPLEMENT_DECL_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_COMPLEMENT_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/parse/detail/complement_fwd.hpp>


namespace fcppt
{
namespace parse
{
namespace detail
{

template<
	typename Parser
>
class complement
:
	private fcppt::parse::tag
{
public:
	explicit
	complement(
		Parser &&
	);

	using
	result_type
	=
	fcppt::parse::result_of<
		Parser
	>;

	template<
		typename Ch,
		typename Skipper
	>
	[[nodiscard]]
	fcppt::parse::result<
		Ch,
		result_type
	>
	parse(
		fcppt::reference<
			fcppt::parse::basic_stream<
				Ch
			>
		>,
		Skipper const &
	) const;
private:
	Parser parser_;
};

}
}
}

#endif
