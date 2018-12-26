//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_CONVERT_DECL_HPP_INCLUDED
#define FCPPT_PARSE_CONVERT_DECL_HPP_INCLUDED

#include <fcppt/function_impl.hpp>
#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/convert_fwd.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Result,
	typename Parser
>
class convert
{
public:
	typedef
	fcppt::function<
		Result (
			fcppt::parse::result_of<
				Parser
			> &&
		)
	>
	convert_function;

	convert(
		Parser &&,
		convert_function &&
	);

	typedef
	Result
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
	Parser parser_;

	convert_function convert_;
};

}
}

#endif
