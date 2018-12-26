//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASIC_LITERAL_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_LITERAL_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/unit_fwd.hpp>
#include <fcppt/parse/basic_literal_fwd.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
class basic_literal
{
public:
	explicit
	basic_literal(
		Ch
	);

	typedef
	fcppt::unit
	result_type;

	template<
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

	Ch
	get() const;
private:
	Ch ch_;
};

}
}

#endif
